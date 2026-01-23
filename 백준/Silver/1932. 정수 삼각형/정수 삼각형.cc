#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int arr[501][501];
int dp[501][501];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 정수 삼각형을 입력받음
	// 정수 삼각형의 값에 해당하지 않는 부분은 자동으로 0 을 배정;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	// dp 를 이용해 정삼각형의 왼쪽 위 대각선과 바로 위 대각선 중 큰 값과 (i,j) 값을 dp[i][j] 에 저장
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	// n 번째 줄에서의 정삼각형의 최대 합의 값을 출력
	int res = -1;
	for (int i = 1; i <= n; i++) {
		if (dp[n][i] > res)
			res = dp[n][i];
	}

	cout << res;

	return 0;
}