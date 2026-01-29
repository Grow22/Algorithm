#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


// n 은 정점의 개수
// m 은 간선의 개수
// start 는 시작 정점
int n, m, start;

// dfs 의 각 정점의 간선을 나타내는 인접행렬 arr
int arr[1001][1001];

// 정점의 방문 여부를 나타낼 벡터 visit
int visit[1001];

void dfs(int x) {

	// 정점 x 를 방문 처리
	visit[x] = 1;
	cout << x << ' ';

	for (int i = 1; i <= n; i++) {
		
		// 간선이 존재할 경우
		if (arr[x][i]) {

			// 노드 i 를 아직 방문하지 않았을 경우
			if (!visit[i]) {
				dfs(i);
			}
		}
	}
}

void bfs(int x) {

	// 시작 정점 x 를 방문처리
	visit[x] = 1;
	cout << x << ' ';
	// 시작 정점 x 를 queue 에 push
	queue<int> q;
	q.push(x);

	int v;
	// (1) 큐가 비어 있지 않은 동안 반복하면서
	while (!q.empty()) {

		// q 에서 맨 앞에 위치하는 원소를 v 에 삽입 후 pop();
		v = q.front();
		q.pop();
		// 정점 x 에 인접한 정점들 중 방문하지 않은 정점들을 전부 큐에 push
		for (int i = 1; i <= n; i++) {
			if(arr[v][i]) {
				if (!visit[i]) {
					q.push(i);
					visit[i] = 1;
					cout << i << ' ';
				}
			}
		}
	}

}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> start;




	// 두 정점을 입력받아 간선으로 처리
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}
	
	dfs(start);
	cout << '\n';
	// visit 배열 초기화
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
	bfs(start);

	return 0;

}