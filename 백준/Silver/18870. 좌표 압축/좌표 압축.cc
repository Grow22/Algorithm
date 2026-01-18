#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;


int main(void) {

	int n;
	cin >> n;

	vector<int> list(n);

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		list[i] = x;
	}
	
	// list 를 오름차순으로 나타내기 위한 vector cop
	vector<int> cop(n);
	cop = list;
	sort(cop.begin(), cop.end());

	vector<int> dp(n);
	dp[0] = 0;
	
	// 초기 dp 값을 설정
	if (cop[0] != cop[1]) {
		dp[1] = 1;
	}
	else {
		dp[1] = 0;
	}
	
	for (int i = 2; i < n; i++) {

		// 만약 오름차순으로 정렬시킨 cop 의 원소가 동일한 원소를 가지지 않을 경우
		// 좌표 압축 값을 dp[i-1] + dp[i-2] 로 설정
		if (cop[i] != cop[i - 1])  dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 1];
	}

	map<int, int> res;
	for (int i = 0; i < n; i++) {
		res[cop[i]] = dp[i];
	}

	for (int i = 0; i < n; i++) {
		cout << res[list[i]] << ' ';
	}

	return 0;
}