#include <iostream>
#define MAX 15
using namespace std;


int col[MAX]; // 각 column 의 말이 저장된 행의 위치를 저장한 배열 col
int N = 0;
int total = 0;

// 체스말을 두어도 되는 지를 확인하는 메서드
int check(int level) {

	// check the same line and diagonal
	for (int i = 0; i < level; i++) {

		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i) {
			return false;
		}
	}

	return true;
}
// parameter x is index about column
void queen(int x) {


	if (x == N) {
		total++;
	}
	else {
		// iterate first row 
		for (int i = 0; i < N; i++) {

			col[x] = i;
			// check the possibility to place the queen
			// if is possible that upper condition then plus x
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