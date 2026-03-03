#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(void) {

	while (1) {

		string s;
		getline(cin, s);

		if (s == ".") break;

		stack<char> v;
		bool b = 1;
		for (int i = 0; i < s.size(); i++) {

			if (s[i] == '(' || s[i] == '[') v.push(s[i]);

			// 오른쪽 괄호가 있을 때 왼쪽 괄호가 없는 경우
			else if (s[i] == ')') {
				if (!v.empty() && v.top() == '(') {
					v.pop();
				}
				// 짝이 맞지 않을 경우
				else {
					b = 0;
					break;
				}
			}
			else if (s[i] == ']') {
				if (!v.empty() && v.top() == '[') {
					v.pop();
				}
				else {
					b = 0;
					break;

				}
			}
		}
		if (b && v.empty()) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

	return 0;
}