#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> v(n + 1); // 배열의 원소값을 저장할 벡터 v
		vector<int> dp(n + 1); // i 번째 원소까지의 합 중 부분배열의 최대값을 나타낼 벡터 dp
		
		// 원소 입력
		for (int j = 1; j <= n; j++) {
			cin >> v[j];
		}

		dp[0] = 0;
		int res = INT_MIN;
		for (int j = 1; j <= n ; j++) {
			dp[j] = max(dp[j - 1] + v[j], v[j]);
			res = max(res, dp[j]);
		}
		cout << res << '\n';
	}

	return 0;

}