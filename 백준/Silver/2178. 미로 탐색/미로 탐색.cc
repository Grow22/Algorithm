#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


/*
	문제 2178: 미로 탐색
*/

int n, m;

// dfs 의 각 정점의 간선을 나타내는 인접행렬 arr
int arr[1001][1001];

// 정점의 방문 여부를 나타낼 벡터 visit
int visit[1001][1001];

int dx[4] = { -1,1,0,0 };
int dy[4] = {0,0,-1,1};

queue<pair<int,int>> q;

void bfs(int x, int y) {

	q.push(make_pair(x, y));
	visit[x][y] = 1;

	// 큐가 비지 않을 동안 반복
	while (!q.empty()) {

		pair<int, int> v = q.front();
		q.pop();

		int x = v.first;
		int y = v.second;

		// 네 방향을 돌면서 탐색 진행
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];

			// 범위를 벗어날 경우
			if (X < 1 || X > n || Y < 1 || Y > m) continue;

			// 진행하려는 좌표가 막혀있거나 방문하였을 경우
			if (!arr[X][Y] || visit[X][Y]) continue;

			q.push(make_pair(X, Y));
			visit[X][Y] = 1;
			arr[X][Y] = arr[x][y] + 1;
		}
	}
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	// arr 에 n * m 만큼 원소를 입력
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {

			if (s[j-1] == '1') {
				arr[i][j] = 1;
			}
			else arr[i][j] = 0;
		}
	}


	
	bfs(1, 1);
	
	// (n,m) 까지 이동한 거리 출력
	cout << arr[n][m];

	return 0;

}