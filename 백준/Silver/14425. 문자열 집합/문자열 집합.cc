#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	map<string, bool> dic;


	string s;
	// n 개의 문자열을 입력하여 문자열 집합에 저장
	for (int i = 0; i < n; i++) {
		cin >> s;
		dic[s] = true;
	}

	// 문자열이 포함되어 있는 지를 검사
	int res = 0;
	for (int i = 0;i < m;i++) {

		cin >> s;
		if (dic[s] == true) res++;
	}

	cout << res;

	return 0;
}