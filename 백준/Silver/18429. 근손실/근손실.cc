#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>


using namespace std;

// n 은 일수
// k 는 감소하는 중량의 값
int n, k;

int cnt;
int visit[9];
int arr[9];
void dfs(int sum, int depth) {

	// sum 이 500 보다 낮을 경우 탐색을 종료하고 return;
	if (sum < 500) {
		return;
	}

	// 3 개를 모두 뽑았을 때 중량이 500 이상일 경우
	if (depth == n) {
		if (sum >= 500) {
			cnt++;
		}
		return;
	}

	else {

		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				visit[i] = 1;
				dfs(sum + arr[i] - k, depth + 1);
				visit[i] = 0;
			}
		}
	}
	

}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(500, 0);

	cout << cnt;

	return 0;
}