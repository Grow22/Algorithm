#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>

using namespace std;


int priority(char c) {

	if (c == '(') {
		return -1;
	}
	else if (c == '+' || c == '-') {
		return 0;
	}
	else if (c == '*' || c == '/') {
		return 1;
	}
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	// 수식 s 를 s 에 입력
	string sr;
	cin >> sr;

	// 연산자를 저장할 스택 s
	stack<char> s;
	
	for (int i = 0; i < sr.size(); i++) {

		char c = sr[i];
		// (1) 연산자일 경우 스택에 푸쉬
		if (c == '*' || c == '/' || c == '+' || c == '-') {

			// (1) - 1스택이 비어 있는 경우 연산자 그냥 push
			if (s.empty()) {
				s.push(c);
			}

			// (1) - 2 스택이 비어 있지 않고
			// 만약 스택에 있는 연산자의 우선순위가 더 높을 경우
			else {
				int p = priority(c);
				while (!s.empty() &&p <= priority(s.top())) {
					cout << s.top();
					s.pop();
				}

				// 이후 현재 진행 중인 연산자 push
				s.push(c);
			}
		}

		// (2) 왼쪽 괄호일 경우 push
		else if (c == '(') {
			s.push(c);
		}
		// (3) 오른쪽 괄호일 경우 
		// 왼쪽 괄호가 나올 떄까지 pop()
		else if (c == ')') {

			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		// (3) 피연산자일 경우 그냥 출력
		else {
			cout << c;
		}
	}

	// (2) 만약 문자를 다 돌았을 경우에도 스택에 연산자가 남아있는 경우 pop 하며 전부 출력
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}