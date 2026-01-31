#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


// n 은 친구의 수 == 노드의 개수
int n;
// x,y 는 x ~ y 까지 계산해야 될 관계
int x, y;

// m 은 관계의 개수
int m;

// 친구 간 연결 관계를 표현할 이차원 배열 arr
int arr[101][101];

int visit[101];

queue<int> q;

int bfs(int x) {

	while (!q.empty()) {

		int v = q.front();
		q.pop();

		// 정점 v 에서 연결된 요소를 파악
		for (int i = 1; i <= n; i++) {

			// 그래프가 존재하고 아직 방문하지 않았으면
			if (arr[v][i] && !visit[i]) {

				q.push(i);
				visit[i] = visit[v] + 1;
			}
		}
	}

	// x 에서 y 에 도달했을 때의 거리를 반환
	return visit[y];
}

int main(void) {

	cin >> n;
	cin >> x >> y;
	cin >> m;

	// a,b 간의 관계를 arr 배열에 저장
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		arr[a][b] = arr[b][a] = 1;
	}


	q.push(x);
	visit[x] = 1;
	bfs(x);
	// 만약 x -> y 의 거리가 존재할 경우 해당 거리를 출력
	// 거리가 존재하지 않을 경우 -1 출력
	if (visit[y]) {
		cout << visit[y]-1;
	}
	else {
		cout << -1;
	}
	
	
	return 0;
}