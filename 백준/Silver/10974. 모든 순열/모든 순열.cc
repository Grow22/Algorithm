#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


/*
	백준 10974: 모든 순열
*/

int n;

int arr[9];
int visit[9];

void dfs(int x) {


	// n 개의 원소를 모두 뽑았을 경우
	if (x == n) {

		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {

		for (int i = 1; i <= n; i++) {

			if (!visit[i]) {
				visit[i] = 1;
				arr[x] = i;
				dfs(x + 1);
				visit[i] = 0;
			}
		}
	}


}


int main(void) {

	
	// N! 순열을 출력할 변수 n 을 입력
	cin >> n;

	dfs(0);
}