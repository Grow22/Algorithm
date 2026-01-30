#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


// m 은 세로 길이
// n 은 가로 길이
int m, n;

int arr[100][100];

// k 는 직사각형의 개수
int k; 


queue<pair<int,int>> q;
int visit[100][100];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int cnt=1;
int bfs(int x,int y) {

	while (!q.empty()) {

		pair<int, int> v = q.front();
		q.pop();
		visit[v.first][v.second] = 1;

		for (int i = 0; i < 4; i++) {
			
			int X = v.first + dx[i];
			int Y = v.second + dy[i];

			// 범위를 벗어낫을 경우
			if (X < 0 || X >= m || Y < 0 || Y >= n) continue;

			// 벽이거나 이미 방문하였을 경우
			if (arr[X][Y] || visit[X][Y]) continue;

			cnt++;
			visit[X][Y] = 1;
			q.push(make_pair(X, Y));

		}

	}

	return cnt;

}
int main(void) {

	// m 은 세로(행)의 길이
	// n 은 가로(열)의 길이)
	cin >> m >> n >> k;

	// k 개의 직사각형의 개수만큼 반복하며 벽을 생성
	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) {
		
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++) {
			for (int s = x1; s < x2; s++) {
				arr[j][s] = 1;
			}
		}
	}


	// 넓이를 나타낼 변수 res
	// 각 구간의 직사각형 구간을 나타낼 변수 x
	vector<int> res;
	int x = 0;
	// bfs 시작
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			// 아직 방문하지 않았고 벽이 아닌 경우
			if (!visit[i][j] && !arr[i][j]) {
				q.push(make_pair(i, j));
				visit[i][j] = 1;
				res.push_back(bfs(i,j));
				x++;
			}
			cnt = 1;
		}
	}

	sort(res.begin(), res.end());

	cout << x << '\n';
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	

	return 0;
}