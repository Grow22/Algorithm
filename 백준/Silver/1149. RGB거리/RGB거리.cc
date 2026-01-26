#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001][4];
int dp[1001][4];

int main(void) {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;


	// 각 집을 칠하는 비용을 입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	// dp 에 초기 값을 미리 저장
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	dp[1][3] = arr[1][3];

	for (int i = 2; i <= n; i++) {
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
		dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
	}
	
	int res = dp[n][1];
	for (int i = 2; i <= 3; i++) {

		if (dp[n][i] < res) {
			res = dp[n][i];
		}
	}
	
	cout << res;

	return 0;
}