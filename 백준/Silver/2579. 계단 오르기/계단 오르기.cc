#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {

	// 계단의 개수를 n 에 입력
	int n;
	cin >> n;

	vector<int> stair(n+1,0);
	vector<int> score(n+1,0); // 각 계단의 점수 중 최대값을 나타낼 vector score

	// 계단의 점수를 stair 에 입력
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		stair[i] = x;
	}
	 
	// 0 ~ 2 까지의 계단의 점수를 먼저 입력
	score[1] = stair[1];
	score[2] = stair[1] + stair[2];
	score[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

	if (n == 1) {
		cout << stair[1];
		return 0;
	}
	else if (n == 2) {
		cout << stair[1] + stair[2];
		return 0;
	}
	else {
		for (int i = 4; i < stair.size(); i++) {
			score[i] = max(score[i - 3] + stair[i - 1] + stair[i], score[i - 2] + stair[i]);
		}
	}

	int result = score[n];
	cout << result;

	return 0;
}