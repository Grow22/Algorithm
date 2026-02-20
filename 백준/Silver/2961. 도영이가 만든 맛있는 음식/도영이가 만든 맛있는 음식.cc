#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int	s[10];
int b[10];

int res = 1000000001;

void solve(int depth, int sumS, int sumB) {

	// 모든 재료를 살펴보았을 경우
	if (depth == n) return;

	res = min(res, abs(sumS * s[depth] - sumB - b[depth]));
	solve(depth + 1, sumS * s[depth], sumB + b[depth]);
	solve(depth + 1, sumS, sumB);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		cin >> b[i];
	}

	solve(0, 1, 0);

	cout << res;

	return 0;
}