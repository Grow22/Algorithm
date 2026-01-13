#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	

	// N 은 숫자의 개수
	// M 은 구해야 하는 합의 개수
	int N, M;

	cin >> N >> M;

	
	vector<int> dp(N+1);
	dp[0] = 0;
	int a;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		dp[i] = dp[i - 1] + a;
	}

	// 부분합 구간을 x,y 에 입력
	int x, y;
	int temp = 0; // 부분합을 임시 저장할 변수 temp
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		temp = dp[y] - dp[x - 1];
		cout << temp << '\n';
	}
	
	return 0;
}