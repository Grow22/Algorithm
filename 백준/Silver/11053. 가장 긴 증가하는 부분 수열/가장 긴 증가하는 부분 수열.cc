#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int arr[1001];
int dp[1001];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 수열의 길이를 나타낼 변수 n
	int n;
	cin >> n;

	// 배열에 수열의 값을 입력
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	
	// i 는 기준이 되는 인덱스
	// j 는 i 인덱스 앞에 위치해 있는 원소들
	for (int i = 1; i <= n; i++) {
		// 각 i 번째 인덱스가 가지는 수열의 수를 1로 변경 후 비교 시작
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	// 가장 큰 증가하는 수열을 출력
	int large = dp[1];
	for (int i = 2; i <= n; i++) {

		if (dp[i] > large) {
			large = dp[i];
		}
	}
	cout << large;
	return 0;
}