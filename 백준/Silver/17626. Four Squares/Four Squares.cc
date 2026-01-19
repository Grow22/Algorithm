#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;


int main(void) {


	// 제곱 수로 나타낼 정수 n 을 입력
	int n;
	cin >> n;

	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i-1] + 1;
		// 이전의 dp 값을 1 증가시킨 값과, 현재 인덱스 i 에 제곱 수를 뺀 인덱스의 dp 값을 비교하여
		// 작은 값을 dp[i] 에 저장
		for (int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];

	return 0;
}