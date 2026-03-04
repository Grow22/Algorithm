#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
vector<string> v;

// 두 문자열이 비슷한 단어인 지 체크
bool solve(string s1, string s2) {

	unordered_map<char, char> m;
	unordered_map<char, bool> valid; // 알파벳이 사용되었는 지를 확인

	for (int i = 0; i < s1.size(); i++) {

		// s1 의 알파벳이 바뀐 적 없고 
		if (!m[s1[i]] && !valid[s2[i]]) {

			m[s1[i]] = s2[i];
			valid[s2[i]] = true;
 		}
		else {
			if (m[s1[i]] != s2[i]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			int res = solve(v[i], v[j]);
			if (res) cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}