#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int board[5][5];
int bingo[5][5];
int res;

// 빙고를 이루었는 지를 체크
void bin_check(int x,int y) {

	int i;
	// 가로 체크
	for (i = 0; i < 5; i++) {
		if (!bingo[x][i]) break;
	}

	if (i == 5) res++;

	// 세로 체크
	for (i = 0; i < 5; i++) {
		if (!bingo[i][y]) break;
	}
	if (i == 5) res++;

	// 좌측 대각선 체크
	if (x == y) {
		for (i = 0; i < 5; i++) {
			if (!bingo[i][i]) break;
		}
		if (i == 5) res++;
	}
	// 우측 대각선 체크
	if (x == (4 - y)) {
		for (i = 0; i < 5; i++) {
			if (!bingo[i][4 - i]) break;
		}
		if (i == 5) res++;
	}
}

// 입력 받은 숫자의 위치를 체크
void check(int num) {


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			// 위치를 발견하였을 경우
			if (board[i][j] == num) {
				bingo[i][j] = true;
				bin_check(i, j);
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 빙고판에 수를 입력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;
	int num;
	while (1) {
		cnt++; 
		cin >> num;
		check(num);

		if (res >= 3) break;
	}
	cout << cnt;
	return 0;
}