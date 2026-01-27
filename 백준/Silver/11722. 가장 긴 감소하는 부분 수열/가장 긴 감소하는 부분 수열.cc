#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 원소의 개수를 의미하는 변수 n
	int n;
	cin >> n;

	vector<int> arr(n + 1);
	vector<int> dp(n + 1);

	// 원소값들을 입력
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	// i 는 기준이 되는 인덱스
	// j 는 i 앞의 원소들을 의미하는 인덱스
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int res = dp[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i] > res) {
			res = dp[i];
		}
	}

	cout << res;
	
	return 0;
}