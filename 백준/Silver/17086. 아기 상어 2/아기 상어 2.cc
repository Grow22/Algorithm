#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// n * m;
int n, m;

// 8 방향으로 이동할 배열 정의
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int arr[50][50];
int dist[50][50];

queue<pair<int,int>> q;
void bfs() {

	while (!q.empty()) {

		pair<int, int> v = q.front();

		int x = v.first;
		int y = v.second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 범위를 벗어날 경우 
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// 이미 방문하였을 경우
			if (dist[nx][ny] != -1) continue;

			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	// 원소 입력 및 dist 거리 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dist[i][j] = -1;
			// 원소 값이 1인 경우 큐에 삽입
			if (arr[i][j] == 1) {
				dist[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	// bfs 실행
	bfs();

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer = max(answer, dist[i][j]);
		}
	}
	cout << answer;

	return 0;
}