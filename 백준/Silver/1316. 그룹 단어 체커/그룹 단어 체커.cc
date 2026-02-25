#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n;


int main(void) {


	cin >> n;

	string s;
	int res = 0;


	for (int i = 0; i < n; i++) {
		cin >> s;

		bool al[26] = { false, };
		al[(int)(s[0]) - 97] = true;

		for (int i = 1; i < s.size(); i++) {

			// 문자가 연속될 경우
			if (s[i - 1] == s[i]) continue;

			// 문자가 연속되지 않고 해당 문자열이 나온 적 있는 경우
			else if (s[i - 1] != s[i] && al[(int)(s[i]) - 97] == true) {
				res++;
				break;
			}

			// i 번째 문자열이 나온 적 없는 경우
			else al[(int)(s[i]) - 97] = true;
		}
	}

	cout << n - res;
	return 0;
}