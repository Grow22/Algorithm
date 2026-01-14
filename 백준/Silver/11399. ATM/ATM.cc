#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int main(void) {

	int N;

	cin >> N;

	vector<int> p;
	int x;
	// 사람의 수 N 만큼 대기시간을 입력 후 vector p 에 저장
	for (int i = 0; i < N; i++) {
		cin >> x;
		p.push_back(x);
	}

	sort(p.begin(), p.end());

	vector<int> dp(1001);
	dp[0] = p[0];
	for (int i = 1; i < N ; i++) {
		dp[i] = dp[i - 1] + p[i];
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += dp[i];

	cout << sum;

	return 0;
}