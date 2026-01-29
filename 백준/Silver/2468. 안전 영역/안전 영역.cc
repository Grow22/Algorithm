#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


// n 은 정점의 개수
int n;

int arr[101][101];
int visit[101][101];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<int,int>> q;


void bfs(int height) {

	while (!q.empty()) {

		pair<int, int> v = q.front();
		q.pop();
		visit[v.first][v.second] = 1;
		// 4 방향으로 돌며 매개 변수 height 보다 높이가 높을 경우 큐에 추가
		for (int i = 0; i < 4; i++) {
			int X = v.first + dx[i];
			int Y = v.second + dy[i];
			// 범위 벗어 날 경우 다음 좌표 진행
			if (X < 0 || X >= n || Y < 0 || Y >= n) continue;
			// height 보다 높이가 크지 않거나 방문했을 경우 다음 좌표 진행
			if (arr[X][Y] <= height || visit[X][Y] ==1) continue;

			// 큐에 삽입 후 방문 처리
			q.push(make_pair(X, Y));
			visit[X][Y] = 1;
		}
	}
	

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);


	// 정점의 개수를 n 에 입력
	cin >> n;

	// 각 도시 별 높이를 입력
	// 제일 높이 입력된 돞이를 height 에 저장
	int height = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			
			if (height < arr[i][j]) {
				height = arr[i][j];
			}
		}
	}


	int res = -1;
	// 높이 1 부터 반복문을 진행
	while (height >= 0) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// 방문할 노드의 높이가 height 보다 크고 아직 방문하지 않았으면
				if (arr[i][j] > height && !visit[i][j]) {
					
					q.push(make_pair(i, j));
					bfs(height);
					cnt++;
				}
			}

		}

		if (cnt > res) {
			res = cnt;
		}

		// 방문 원소, cnt 초기화
		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = 0;
			}
		}

		// 높이 감소
		height--;
	}

	// 결과 출력
	cout << res;
	return 0;

}