#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n, m;
int arr[9];

void dfs(int x) {


	// k 개의 정수를 모두 뽑은 경우
	if (x == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}

	// k 개의 정수를 아직 뽑지 못한 경우
	else {

		for (int i = 1; i <= n; i++) {
				arr[x] = i; // x 번째 뽑은 위치에 정수 i 를 배치
				dfs(x + 1);
		}
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	dfs(0);
	return 0;
}