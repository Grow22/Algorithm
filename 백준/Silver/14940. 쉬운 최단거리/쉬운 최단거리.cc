#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


/*
	백준 14940: 쉬운 최단거리
*/

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n,m;

// 지도의 땅과 목표지점을 나타낼 배열 arr
int arr[1001][1001];
int visit[1001][1001];

queue<pair<int, int>> q;

void bfs(int a, int b) {

	q.push(make_pair(a, b));
	visit[a][b] = 1;

	while (!q.empty()) {

		pair<int, int> v = q.front();
		q.pop();
		
		int x = v.first;
		int y = v.second;

		// 네 방향으로 탐색하면서
		for (int i = 0; i < 4; i++) {
			
			int X = x + dx[i];
			int Y = y + dy[i];

			// 벽이거나 범위를 벗어난 경우
			if (!arr[X][Y] || X < 1 ||  X > n || Y > m || Y < 1) continue;

			// 이미 방문한 지점일 경우
			if (visit[X][Y]) continue;

			// 길이 존재하고(1) 아직 방문하지 않았을 경우 현재 거리에 + 1 한 값을 배정
			q.push(make_pair(X, Y));
			visit[X][Y] = 1;
			arr[X][Y] = arr[x][y] + 1;
		}
	}
}

int main(void) {

	// n 은 세로 길이
	// m 은 가로 길이
	cin >> n >> m;


	pair<int, int> target;
	// 길과 목표지점을 배열 arr 에 입력 후
	// 목표 지점을 target 에 저장
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				target = make_pair(i, j);
				arr[i][j] = 0;
			}
		}
	}

	bfs(target.first, target.second);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			// 만약 길이 존재하지만 방문할 수 없는 땅일 경우 -1 을 출력
			if (arr[i][j] && !visit[i][j]) {
				cout << -1 << ' ';
				continue;
			}
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}