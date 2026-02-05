#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>


using namespace std;

// k 는 뽑아야 하는 원소의 개수
int k;

int lotto[14];
int arr[6];

void dfs(int start, int depth) {

	// 6 개의 수를 모두 뽑은 경우
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// k 개의 숫자 전부를 돌며 dfs 탐색 진행
	for (int i = start; i < k; i++)
	{
		arr[depth] = lotto[i];
		dfs(i + 1, depth + 1);
	}
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {

		// k 가 0일 경우 종료
		cin >> k;
		if (!k) break;

		// k 개의 원소를 arr 에 입력
		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		}

		dfs(0, 0);
		cout << '\n';
	}

	return 0;
}