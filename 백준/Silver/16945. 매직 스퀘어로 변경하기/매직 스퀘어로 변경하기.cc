#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[9];
vector<int> pick(9);

// 매직스퀘어를 이루는 지를 검사
bool check(vector<int> p) {

	int sum = p[0] + p[1] + p[2];

	// 행의 값의 합이 다를 경우
	if (sum != (p[3] + p[4] + p[5])) return false;
	if (sum != (p[6] + p[7] + p[8])) return false;

	// 열의 값의 합이 다를 경우
	if(sum != (p[0] + p[3] + p[6])) return false;
	if(sum != (p[1] + p[4] + p[7])) return false;
	if (sum != (p[2] + p[5] + p[8])) return false;

	// 대각선의 값의 합이 다를 경우
	if(sum != (p[0] + p[4] + p[8])) return false;
	if (sum != (p[2] + p[4] + p[6])) return false;

	return true;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 배열 값 입력 및 초기화

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		pick[i] = i + 1;
	}
	int res = -1;

	do {

		int diff = 0;
		// 벡터 pick 가 매직스퀘어를 구성하고 있는 경우
		if (check(pick)) {
			for (int i = 0; i < 9; i++) {
				diff += abs(pick[i] - arr[i]);
			}
			// pick 을 이루는 매직스퀘어의 값의 차가 가장 작을 경우
			// 해당 값으로 업데이트
			if (res == -1 || res > diff) {
				res = diff;
			}
		}
	} while (next_permutation(pick.begin(), pick.end()));

	cout << res;

	return 0;
}