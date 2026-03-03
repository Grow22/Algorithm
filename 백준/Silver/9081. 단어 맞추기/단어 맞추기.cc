#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int T;


void solve(string s) {

}
int main(void) {

	cin >> T;

	for (int i = 0; i < T; i++) {
		
		string s;
		cin >> s;
		
		// 다음 문자열이 없을 경우
		// 이전 문자열로 되돌림
		if (!next_permutation(s.begin(), s.end())) {
			prev_permutation(s.begin(), s.end());
		}

		cout << s << '\n';
	}
	
	return 0;
}