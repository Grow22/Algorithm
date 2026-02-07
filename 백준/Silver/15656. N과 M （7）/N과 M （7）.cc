#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

/*
	백준 15654
	문제: N과 M (5)
*/

using namespace std;

int n, m;

int first[9];
int arr[9];
int visit[9];

void dfs(int start, int x) {

	// n 개의 원소 중 m 개의 원소 모두 뽑았을 경우
	if (x == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {

		for (int i = 0; i < n; i++) {
			arr[x] = first[i];
			dfs(i + 1, x + 1);
		}
	}

}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	// n 개의 원소를 배열 arr 에 입력
	for (int i = 0; i < n; i++) {
		cin >> first[i];
	}

	// arr 을 오름차순으로 정렬
	sort(first, first + n);


	dfs(0, 0);

	return 0;
}