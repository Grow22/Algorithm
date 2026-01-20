#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;
int arr[100];

void dfs(int num, int k) {

	// 정수값 M 개를 모두 뽑은 경우 해당 경우를 모두 출력
	if (k == M) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	// 정수값 M 개를 뽑을 때까지 다음 정수를 진행
	else {

		for (int i = num; i <= N; i++) {
			arr[k] = i;
			dfs(i + 1, k + 1);
		}
	}
}


int main(void) {

	// N 은 1부터 N 까지 나타낼 정수의 수
	// M 은 뽑아야 하는 정수의 개수
	cin >> N >>M;


	dfs(1, 0);
}