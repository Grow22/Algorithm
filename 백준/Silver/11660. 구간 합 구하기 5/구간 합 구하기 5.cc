#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	int x;
	// dp 에 (0,0) 부터 (i,j) 까지의 정수들의 합을 dp[i][j] 에 저장
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x;
			arr[i][j] = x;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i-1][j-1] + arr[i][j];
		}
	}

	int x1, y1, x2, y2;
	int res = 0;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		res = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1-1][y1-1];
		cout << res << '\n';
	}

	return 0;
}