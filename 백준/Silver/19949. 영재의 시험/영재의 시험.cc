#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10];
int p[10];

int res;
void solve(int depth, int sum) {

	// 문제의 끝까지 채점하였을 경우
	if (depth == 10) {
		// 채점한 점수가 5 점 이상일 경우
		if (sum >= 5) {
			res++;
		}
		return;
	}

	for (int i = 1; i <= 5; i++) {
		
		// 중복되는 정답을 3개 연속으로 찍었을 경우
		if (depth >= 2 && ((i == p[depth - 1])) && (i == (p[depth - 2]))) continue;
		
		p[depth] = i;
		if (arr[depth] == i) solve(depth + 1, sum + 1);
		else solve(depth + 1, sum);
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	solve(0, 0);

	cout << res;

	return 0;
}