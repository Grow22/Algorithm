#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int N; // number of variable
int operands[12];
int operators[4];

int mymax = -1000000001;
int mymin = 1000000001;

void solve(int total, int cnt) {


	// 모든 변수를 계산하였을 경우
	if (cnt == N) {

		if (total > mymax) {
			mymax = total;
		}
		if (total < mymin) {
			mymin = total;
		}
		return;
	}

	// 계산해야 할 변수가 남아있을 경우
	else {

		for (int i = 0; i < 4; i++) {

			// 계산해야 할 연산자가 i 번째 인덱스에 존재할 경우
			if (operators[i] > 0) {
				operators[i]--;

				if (i == 0) {
					solve(total + operands[cnt], cnt + 1);
				}
				else if (i == 1) {
					solve(total - operands[cnt], cnt + 1);
				}
				else if (i == 2) {
					solve(total * operands[cnt], cnt + 1);
				}
				else if (i == 3) {
					solve(total / operands[cnt], cnt + 1);
				}
				operators[i]++;
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> operands[i];
	}

	// 각 연산자의 개수를 입력
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	solve(operands[0], 1);

	cout << mymax << '\n';
	cout << mymin;
	return 0;
}