#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {

	string sr;

	cin >> sr;
	stack<int> s;


	for (int i = 0; i < sr.size(); i++) {

		// (1) 왼쪽 괄호인 경우 -1 을 스택에 push
		if (sr[i] == '(') {
			s.push(-1);
		}

		// (2) 정수인 경우
		else if (isalnum(sr[i])) {
			// (2)-1 뒤에 '(' 괄호가 등장할 경우 스택에 해당 정수를 그대로 push
			if (i < sr.size() - 1 && sr[i + 1] == '(') {
				s.push(sr[i] - '0');
			}
			else {
				s.push(1);
			}
		}
		// (3) 오른쪽 괄호일 경우 -1 을 만날 때까지 정수개수를 count 하며 pop
		else {
			int len = 0;
			while (s.top() != -1) {
				len += s.top();
				s.pop();
			}

			// 왼쪽 괄호를 제거 후 괄호 앞의 정수를 len 에 곱해준 후 해당 원소를 pop
			s.pop();
			len *= s.top();
			s.pop();
			s.push(len);
		}
	}

	// 만약 스택이 비어있지 않은 경우
	// 해당 원소들을 모두 pop 하며 len 증가
	// ex) 123 같은 경우
	int res = 0;
	while (!s.empty()) {
		res += s.top();
		s.pop();
	}

	cout << res;
	return 0;
}