#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


// n 은 상자의 세로 수, 
// m 은 상자의 가로 수
int n, m;
int arr[1001][1001];

queue<pair<int,int>> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 방문 여부를 나타낼 배열 visit
int visit[1001][1001];

void bfs() {

	// 큐가 비지 않은 동안 반복하면서
	while (!q.empty()) {

		pair<int, int> v = q.front();
		q.pop();
		// 상,하,좌,우 로 돌며 좌표에 갈 수 있을 시 큐에 삽입
		for (int i = 0; i < 4; i++) {
			int X = v.first + dx[i];
			int Y = v.second + dy[i];

			// 범위를 벗어날 시 다음 방향으로 진행
			if (X < 0 || X >= n || Y < 0 || Y >= m) continue;

			// 길이 막혀있거나(-1) 이미 방문했을 경우 continue
			if (arr[X][Y] == -1 || visit[X][Y] == 1) continue;

			// 방문처리 후 큐에 삽입
			visit[X][Y] = 1;
			arr[X][Y] = arr[v.first][v.second] + 1;
			q.push(make_pair(X, Y));
		}

		

	}
}


int main(void) {

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
				visit[i][j] = 1;
			}
		}
	}

	bfs();


	int result = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			// 토마토가 위치할 수 있는 공간이면서 토마토가 익지 않은 경우
			if (arr[i][j] != -1 && visit[i][j] == 0) {
				cout << -1;
				return 0;
			}

			if (arr[i][j] > result) {
				result = arr[i][j];
			}
		}
	}

	cout << result-1;

	return 0;
}