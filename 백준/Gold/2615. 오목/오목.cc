#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[19][19];

// 가로, 세로, 오른쪽 대각선 위, 오른쪽 대각선 아래
int dx[4] = {0,1,-1,1};
int dy[4] = {1,0,1,1};

// 범위에 포함되는 지를 검사
bool isValid(int x, int y) {
	return x >= 0 && x < 19 && y >= 0 && y < 19;
}

bool check(int x, int y) {


	if (arr[x][y] == 0) return 0;

	// 네 방향으로 오목이 성립하는 지를 확인
	for (int i = 0; i < 4; i++) {
		// 현재 돌의 반대 방향의 좌표
		int X = x - dx[i];
		int Y = y - dy[i];

		// 1. 반대 방향에 돌디 존재할 경우 시작지점이 아니므로 다음 방향으로 탐색 진행
		if (isValid(X, Y) && arr[X][Y] == arr[x][y]) continue;
		// 2, 유효한 방향으로 탐색을 진행하여 연속되는 색깔의 바둘알을 검사

		int nextX = x + dx[i];
		int nextY = y + dy[i];
		int cnt = 1;
		// 현재 위치에서 다음 방향으로 탐색을 진행하여 같은 색의 바둑알일 경우 개수를 카운트
		while (isValid(nextX, nextY) && arr[nextX][nextY] == arr[x][y]) {
			cnt++;
			nextX += dx[i];
			nextY += dy[i];
		}
		if (cnt == 5) {
			return true;
		}
	}

	// x,y 위치에서 연속되는 같은 색의 바둑알 5 개를 찾지 못했을 경우 false 반환
	return false;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (check(i, j)) {
				cout << arr[i][j] << '\n';
				cout << i + 1 << ' ' << j + 1;
				return 0;	
			}
		}
	}

	// 승부가 결정되지 않을 경우 0 을 출력
	cout << 0;

	return 0;
}