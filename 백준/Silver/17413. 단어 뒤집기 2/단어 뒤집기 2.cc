#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string s;
stack<char> v;

void print(stack<char>& s) {

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main(void) {

	getline(cin, s);
	
	for (int i = 0; i < s.size(); i++) {

		// 왼쪽 괄호(<)일 경우
		if (s[i] == '<') {
			print(v);
			while (1) {
				cout << s[i];
				if (s[i] == '>')
					break;
				i++;
			}
		}
		else if (s[i] == ' ') {
			print(v);
			cout << " ";
		}
		// 그냥 문자인 경우
		else {
			v.push(s[i]);
		}
	}
	print(v);
	return 0;
}