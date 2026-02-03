#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n;
int arr[21];
int roma[4] = { 1,5,10,50 };
int res = 0;
int visit[1001];

void dfs(int cnt, int idx, int sum) {

	// (1) 뽑아야 할 개수 n 만큼 원소를 cnt 개 뽑았을 경우
	if (cnt == n) {

		// 만약 구한 합의 값 sum 이 아직 중복된 값일 경우
		if (visit[sum]) {
			return;
		}
		else {
			visit[sum] = 1;
			res++;
		}
		
	}

	// (2) 현재 원소부터 시작하여 다음 원소를 탐색 진행
	else {

		for (int i = idx; i < 4; i++) {
			dfs(cnt + 1, i, sum + roma[i]);
		}

	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	dfs(0,0,0);

	cout << res;
	return 0;
}