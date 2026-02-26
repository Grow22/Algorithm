#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

string s;
int arr[26] = { 0, };

int main(void) {

	cin >> s;

	int x;
	for (int i = 0; i < s.size(); i++) {
		x = s[i] - 'A';
		arr[x]++;
	}


	int cnt=0;

	int pos = 0;
	int start = 0;
	int end = s.size() - 1;
	for (int i = 0; i < 26; i++) {

		// i 번째 문자의 개수가 홀수일 경우
		if (arr[i] % 2 != 0) {
			cnt++;
			s[end / 2] = i + 'A';
		}

		for (int j = 0; j < arr[i] / 2; j++) {
			s[start + pos] = i + 'A';
			s[end - pos] = i + 'A';
			pos++;
		}

		//cout << s << '\n';

	}

	if (cnt > 1) {
		cout << "I'm Sorry Hansoo";
	}
	else cout << s;

	return 0;
}