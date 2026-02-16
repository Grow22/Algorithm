#include <iostream>
#define MAX 15
using namespace std;


int col[MAX]; // 각 column 의 말이 저장된 행의 위치를 저장한 배열 col
int N = 0;
int total = 0;

// 체스말을 두어도 되는 지를 확인하는 메서드
int check(int level) {

	// 현재의 level 번째 위취에 퀸을 놓을 수 있는 지 모든 col 과 비교
	for (int i = 0; i < level; i++) {
		
		// level col 이전에 위치한 퀸과 
		// 같은 행에 위치했거나 대각선에 위치하였을 경우
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
			return false;
	}
	return true;
	
}
// parameter x is index about column
void queen(int x) {

	// 모든 열에 퀸을 배치하였을 경우
	if (x == N) {
		total++;
	}

	else {

		for (int i = 0; i < N; i++) {
			col[x] = i;

			// 현재 x 번째 col 의 퀸이 놓여질 조건을 만족할 경우 
			// 다음 열의 퀸의 위치에 대한 검사 진행
			if (check(x)) {
				queen(x + 1);
			}
		}
	}
}

int main() {

	// n 의 개수를 입력
	cin >> N;
	queen(0);
	cout << total;

	return 0;

}