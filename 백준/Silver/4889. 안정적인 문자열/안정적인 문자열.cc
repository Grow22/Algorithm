#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1; // t 는 나타낼 순번을 의미
	while (1) {

		string s;
		stack<char> st;

		int result = 0; // 문자 변경 횟수를 의미
		cin >> s;
		if (s[0] == '-') break;


		for (int i = 0; i < s.size(); i++) {

			// 문자열이 쌍을 이룰 경우 pop
			if (s[i] == '}' && !st.empty() && st.top() == '{')
				st.pop();
			// 쌍을 이루지 않을 경우 괄호 push
			else st.push(s[i]);
		}
		// 스택이 빌 때 동안 반복
		while (!st.empty()) {

			// 가장 최상단의 문자를 비교
			char c1 = st.top();
			st.pop();
			char c2 = st.top();
			st.pop();

			// 두 문자가 같은 경우 결과 1 증가
			if (c1 == c2) result++;
			else result += 2;
		}
		cout << t << ". " << result << '\n';
		t++;
	}

	return 0;
}