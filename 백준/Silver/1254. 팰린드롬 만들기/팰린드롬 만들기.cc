#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

string sr;

int pal(int L, int R) {

	// 문자열의 시작과 끝에서 시작하여 pal 인지 여부를 검사
	while (L < R) {
		if (sr[L] != sr[R]) {
			return 0;
		}
		L++; R--;
	}
	// pal 을 만족할 경우 1 을 반환
	return 1;
}

int main(void) {

	
	cin >> sr;


	int len = sr.size();
	// 문자열의 길이만큼 반복문을 돌며
	for (int i = 0; i < sr.size(); i++) {

		// (1) 만약 palindrome 을 만족할 경우
		// 반복문을 멈추고 해당 index 와 문자열 길이를 합한 값을 문자열 길이로 반환
		if (pal(i, len -1)) {
			len += i;
			break;
		}
	}

	cout << len;
	return 0;
}