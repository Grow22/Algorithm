#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


/*
	백준 1743: 음식물 피하기
*/


// n 은 세로 길이, m 은 가로 길이, k 는 쓰레기의 개수
int n, m, k;

int arr[101][101];
int visit[101][101];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<pair<int, int>> q;

int bfs(int a, int b) {

	// 음식물 쓰레기의 값을 나타낼 변수 cnt
	int cnt= 1; 

	q.push(make_pair(a, b));
	visit[a][b] = 1;

	while (!q.empty()) {
		
		pair<int, int> v = q.front();
		q.pop();

		int x = v.first;
		int y = v.second;

		// 네 가지 방향으로 탐색 시작
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];


			// 범위를 벗어났을 경우
			if (X < 1 || X > n || Y < 1 || Y > m) continue;


			// (X,Y) 좌표에 쓰레기가 존재하는 경우 방문하지 않았을 경우
			if (arr[X][Y] && !visit[X][Y]) {
				
				// 큐에 해당 위치를 저장 후 쓰레기의 값을 1 증가
				q.push(make_pair(X,Y));
				visit[X][Y] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void) {

	cin >> n >> m >> k;	

	int x, y;
	// 쓰레기를 배열 arr 에 입력
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
	}

	int largest = -999;
	// bfs 를 통해 가장 큰 쓰레기의 크기를 각 배열에 저장
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= m; j++) {

			// (i,j) 좌표에 대해 방문하지 않았을 경우 bfs 실행
			if (arr[i][j] && !visit[i][j])
			{
				int res = bfs(i, j);

				if (res > largest) {
					largest = res;
				}
			}
		}
	}

	
	cout << largest;

	return 0;
}