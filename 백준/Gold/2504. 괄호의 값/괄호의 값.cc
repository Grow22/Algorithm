#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {

	string sr;

	cin >> sr; 

	stack<int> s;

	int temp=1;
	int res=0;

	char pre =' ';
	for (int i = 0; i < sr.size(); i++) {

		// 1) 왼쪽 괄호인 경우 push 후 temp 에 괄호의 값을 mul
		if (sr[i]  == '(' || sr[i] == '[') {

			s.push(sr[i]);
			// '(' 인 경우
			if (sr[i] == '(') {
				temp *= 2;
			}
			else {
				temp *= 3;
			}
		}
		
		// 2) 오른쪽 괄호인 경우 
		else {

			// 스택이 비어져있는 경우 return 0;
			if (s.empty()) {
				res = 0;
				break;
			}
			// 2) -1  ')' 괄호인 경우
			if (sr[i] == ')') {
				
				
				// 1) 괄호의 짝이 맞지 않을 경우 0 반환
				if (s.top() == '[') {
					res = 0;
					break;
				}

				s.pop();
				// 2) 현재 문자열과 이전 문자열이 짝이 맞을 경우
				// res 에 temp 값을 더한 후 temp 를 괄호값으로 나눔
				if (pre == '(') {
					res += temp;
					temp /= 2;
				}
				// 4) 괄호가 중복될 경우 temp 만 괄호값으로 나눔
				else {
					temp /= 2;
				}
				
			}
			
			// 2-2) ']' 괄호인 경우
			else {
				if (s.top() == '(') {
					res = 0;
					break;
				}
				s.pop();
				// 2-1) 케이스와 동일하게 진행(괄호의 연산값만 3으로 변경)
				if (pre == '[') {
				res += temp;
				temp /= 3;
			}
				else {
					temp /= 3;
				}
			}
			
		}
		pre = sr[i];
	}

	if (!s.empty()) {
		res = 0;
	}
	cout << res;
	return 0;
}