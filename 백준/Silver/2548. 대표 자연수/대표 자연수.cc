#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n);

	// 원소 입력
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// 원소 정렬
	sort(v.begin(), v.end());

	int res;
	// 원소의 개수가 짝수일 경우
	if (n % 2== 0) res = v[n/2 -1];
	else res = v[v.size() / 2];

	cout << res;
	return 0;
}