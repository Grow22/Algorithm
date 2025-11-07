#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {


	string s;
	int x;

	vector<string> result;
	

	// 입력할 데이터 개수를 x 에 입력
	cin >> x;

	// (1) 입력한 정수 x 만큼 반복


	for (int i = 0; i < x; i++) {

		// (2) s 에 문자열 입력
		cin >> s;

		int r = 1;
		stack<char> st;
		for (int j = 0; j < s.length(); j++) {

			//  (1) 왼쪽 괄호인 경우 push
			if (s[j] == '(') {
				st.push(s[j]);
			}
			// (2) 오른쪽 괄호인 경우 pop
			else if (s[j] == ')') {
				
				// (2) -1 pop 할 원소가 없으면 탈출
				if (st.empty()) {
					r = 0;
					result.push_back("NO");
					break;
				}
				// (2) -2 pop 할 원소가 있는 경우 pop()
				else {
					st.pop();
				}
			}
		}

		if (r == 1) {
			// 문자를 다 돌았을 때 원소가 없는 경우 Success
			if (st.empty()) {
				result.push_back("YES");
			}
			// 원소가 남아있는 경우 Fail
			else {
				result.push_back("NO");
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {

		cout << result[i] << endl;
	}
}