#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// W 는 각 물건의 무게, V 는 각 물건의 가치
int W[101] = { 0, };
int V[101] = { 0, };
int dp[101][100001];


int main(void) {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	// N 은 물건의 개수
	// K 는 버틸 수 있는 무게
	int n, k;
	cin >> n >> k;

	
	// 물건의 무게와 가치를 입력
	for (int i = 1; i <= n; i++) {
		cin >> W[i] >> V[i];
	}

	
	// 반복문에서 i 는 K 까지 진행하며 담을 수 있는 무게의 값
	// row 는 행을 나타내며 고려할 물건의 수를 나타냄
	for (int i = 1; i <= k; i++) {
		for (int row = 1; row <= n; row++) {
			
			// 물건의 크기가 담을 수 있는 무게 k 보다 클 경우 이전의 값을 배치
			if (W[row] > i) {
				dp[row][i] = dp[row-1][i];
			}
			// 물건의 크기를 담을 수 있는 무게 k 에 담을 수 있는 경우
			// dp[row][j] = max(dp[row-1][i], dp[row-1][i-w[row]] + v[row]
			else {
				dp[row][i] = max(dp[row - 1][i], dp[row - 1][i - W[row]] + V[row]);
			}
		}
	}

	cout << dp[n][k];

	return 0;
}