#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


// T 는 테스트 케이스
int T;
// n 은 원소의 개수
int n;

int arr[1001][1001];
int visit[1001];

void dfs(int x) {

	
	visit[x] = 1;
	for (int i = 1; i <= n; i++) {

		// 간선이 존재하고 아직 방문하지 않았을 시
		if (arr[x][i]) {
			if (!visit[i]) {
				dfs(i);
			}
		}
	}

}

int main(void) {

	cin >> T;
	

	for (int i = 0; i < T; i++) {

		cin >> n;
		// n개 만큼의 입력된 원소를 저장할 벡터 v
		vector<int> v(n+1);

		// n 만큼의 원소를 입력후 arr[i][x] 에 간선을 저장
		int x;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			arr[i][x] = 1;
		}

		int cnt = 0;
		// 1 부터 n 까찌 dfs 를 반복하며 사이클의 개수를 구함
		for (int i = 1; i <= n; i++) {

			// i 번째 원소가 아직 방문되지 않았을 시 dfs 실행
			if (!visit[i]) {

				dfs(i);
				cnt++;
			}
			
		}

		cout << cnt << '\n';

		// arr, visit 배열 초기화
		for (int i = 1; i <= n; i++) {
			visit[i] = 0;
			for (int j = 1; j <= n; j++) {
				arr[i][j] = 0;
			}
		}
	}

	return 0;
}