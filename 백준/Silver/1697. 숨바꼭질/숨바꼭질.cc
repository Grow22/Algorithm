#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


// n 은 수빈의 시작 위치
// k 는 동생의 위치
int n, k;

queue<pair<int, int>> q;
// 방문했는 지를 나타낼 벡터 v
vector<int> visit(100001);

void bfs(int a) {


	// 초기 위치 a 와 초기 횟수 0 을 큐에 push
	q.push(make_pair(a, 0));
	visit[a] = 1;
	// 큐가 비어있지 않은 동안 반복
	while (!q.empty()) {

		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == k) {
			cout << cnt;
			break;
		}

		// x+1 의 값이 범위 안에 존재할 시
		if (x+1 >= 0 && x+1<= 100000) {

			if (!visit[x + 1]) {
				visit[x + 1] = 1;
				q.push(make_pair(x + 1, cnt + 1));
			}
		}
		// x-1 의 값이 범위 안에 존재할 시
		if (x - 1 >= 0 && x - 1 <= 100000) {

			if (!visit[x - 1]) {
				visit[x - 1] = 1;
				q.push(make_pair(x - 1, cnt + 1));
			}
		}
		
		// x*2 가 범위 안에 존재할 시
		if (x * 2 >= 0 && x * 2 <= 100000) {
			if (!visit[x * 2]) {
				visit[x * 2] = 1;
				q.push(make_pair(x * 2, cnt + 1));
			}
		}
	}
}

int main(void) {

	cin >> n >> k;
	bfs(n);

	return 0;
}	