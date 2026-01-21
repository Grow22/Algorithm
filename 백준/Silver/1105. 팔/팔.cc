#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string L, R;

	cin >> L >> R;
	int min = 0;
	// 1) 두 문자열의 길이가 다른 경우 0 을 출력
	if (L.size() != R.size()) {
		cout << '0';
	}

	else {
	for (int i = 0; i < L.size(); i++) {
		// 2-1)  i 번째 인덱스의 정수 값이 8 이 아닌 경우
		if (L[i] != R[i]) break;
		// 2-2) i 번째 인덱스의 정수 값이 8 인 경우
		if (L[i] == R[i] && L[i] == '8') min++;
		}
	cout << min;
	}
	return 0;
}