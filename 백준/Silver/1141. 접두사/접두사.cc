#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	// 접두어 X 의 집할을 나타낼 변수 cnt
	int cnt = n;
	// h hi hello return run running
	for (int i = 0; i < n-1; i++) {
		string s = v[i + 1].substr(0, v[i].size());

		// 접두어에 해당할 경우
		if (s == v[i]) {
			cnt--;
		}
	}

	cout << cnt;

	return 0;
}