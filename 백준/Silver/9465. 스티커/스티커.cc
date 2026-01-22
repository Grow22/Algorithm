#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


int arr[2][100000];
int dp[2][100001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// T is num of test case
	// n is num of column
	int T;
	int n;
	cin >> T;

	int x;
	// 테스트 케이스만큼 반복하면서
	for (int i = 0; i < T; i++) {
		cin >> n;
		// 2차원 배열에 원소들을 저장
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> x;
				arr[j][k] = x;
			}
		}
		// dp[0][0], dp[1][0], dp[0][1], dp[1][1] 의 값에 초기 값을 설정
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1], dp[1][1] = arr[1][1];
		for (int a = 2; a <= n; a++) {
			dp[0][a] = max(dp[1][a - 1], dp[1][a - 2]) + arr[0][a] ;
			dp[1][a] = max(dp[0][a - 1], dp[0][a - 2]) + arr[1][a];
		}

		// 마지막 값까지 값을 구했을 때 더 큰 합을 출력
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}



	return 0;
}