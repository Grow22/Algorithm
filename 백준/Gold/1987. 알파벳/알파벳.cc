#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int r, c;
int arr[20][20];
int visit[26]; // A ~ Z 까지의 방문을 나타낼 배열 visit

// 위, 아래, 왼쪽, 오른쪽
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int res;
void dfs(int x, int y, int depth) {

	res = max(res, depth);
	// (1,1) 열의 원소를 큐에 삽입
	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];

		// 다음으로 진행할 좌표가 범위 안에 있을 경우
		if (X >= 0 && X < r && Y >= 0 && Y < c) {
			// 해당 위치의 영문자가 아직 나오지 않은 경우
			if (!visit[arr[X][Y] - 'A']) {
				visit[arr[X][Y] - 'A'] = true;
				dfs(X, Y, depth + 1);
				visit[arr[X][Y] - 'A'] = false;
			}
		}
	}
}

int main(void) {

	cin >> r >>  c;

	// 원소 입력
	string s;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			arr[i][j] = s[j];
		}
	}
	
	visit[arr[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << res;
	return 0;
}