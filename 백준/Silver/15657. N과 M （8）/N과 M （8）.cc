#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int n, m;

int first[9];
int arr[9];
int visit[9];

// num 은 기준이 될 first 배열의 index
// x 는 선택한 원소의 개수
void dfs(int num, int x) {

	// k 개의 정수를 모두 뽑은 경우
	if (x == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}

	// k 개의 정수를 아직 뽑지 못한 경우
	else {

		for (int i = num; i < n; i++) {
			// 비내림차순일 경우에만 원소를 삽입 
				arr[x] = first[i]; // x 번째 뽑은 위치에 정수 i 를 배치
				dfs(i,x + 1);
		}
		}
	}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	
	for (int i = 0; i < n; i++) {
		cin >> first[i];
	}
	
	sort(first, first+n);
	dfs(0,0);
	return 0;
}