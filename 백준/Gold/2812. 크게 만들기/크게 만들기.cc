#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>

using namespace std;

int main(void) {

	// N 은 입력받을 정수의 개수,
	// K 는 제거할 수의 개수
	int N, K;

	string sr;
	cin >> N;
	cin >> K;
	cin >> sr;
	int cnt = 0; // N 의 자리에서 제거한 숫자의 개수를 cnt 에 저장

	// 제거 이후 정수를 나타낼 스택 s
	stack<char> s;
	// s 의 원소를 역순으로 저장할 스택 s2
	stack<char> s2; 

	// 1) K 개의 원소를 제거할 동안 반복 진행
	
	for (int i = 0; i < sr.size(); i++) {
			
		// 스택이 비어있지 않고 제거한 정수의 개수가 K 값보다 작으면서
		// 스택의 top() 값이 현재 정수보다 작을 경우 
		// 해당 정수를 전부 pop()
		while (!s.empty() && cnt < K && sr[i] > s.top()) {
			cnt++;
			s.pop();
		}

		// (2) 현재 정수를 스택에 push
		s.push(sr[i]);
	}

	// (2) 제거해야 할 정수가 남아있는 경우 추가로 제거
	while (cnt < K) {
		cnt++;
		s.pop();
	}


	// (3) 결과를 출력하기 위해 스택 s 를 역순으로 스택 s2 에 저장
	while (!s.empty()) {

		s2.push(s.top());
		s.pop();
	}

	// 결과 출력
	while (!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}

	return 0;
}