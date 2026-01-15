#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(void) {

	int x;
	cin >> x;
	vector<int> dp(x + 1, 0);

	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;

		if ((i % 2) == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
		if ((i % 3) == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
	}

	cout << dp[x];

	return 0;
}