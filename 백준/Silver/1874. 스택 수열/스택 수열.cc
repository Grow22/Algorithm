#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;


int main(void) {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// (1) 정수 n 입력
	int n;
	cin >> n;

	int x;

	
	stack<int> s;

	vector<char> r; // 결과를 저장할 r

	int a = 1;
	for (int i = 0; i < n; i++) {

		// (2) 정수 x 입력
		cin >> x;

		//(2) - 1 스택이 비어있을 시 x 와 같아질 때 까지 push
		 
		if (s.empty()) {

			s.push(a++);
			r.push_back('+');
			while (s.top() < x) {
				s.push(a++);
				r.push_back('+');
			}
		}
		// (2) - 2 스택이 비어있지 않을 경우
		else  {

			// 스택의 top 값이 x 값보다 클 경우
			if (s.top() > x) {
				cout << "NO";
				return 0;
			}

			while (s.top() < x) {
				s.push(a++);
					r.push_back('+');
			}

		}
		
		// (3) 만약 x 와 top 의 값이 같을 시 pop
		while (!s.empty() &&s.top() >= x) {
			s.pop();
			r.push_back('-');
		}
	}

	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << '\n';
	}

	return 0;
}