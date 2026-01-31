#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


// n 은 유저의 수
// m 은 친구 관계의 수
int n, m;

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
				visit[i] = visit[v] +1;
			}
		}
	}

	// 최소 거리를 res 에 저장
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		// 시작 정점을 제외한 정점 중 거리가 가장 작은 값을 지니는 값을 res 에 저장
		if (i != x) {
			sum += visit[i];
		}
	}
	return sum;
}

int main(void) {


	cin >> n >> m;

	// 친구 관계를 입력 받은 후 배열에 저장
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		arr[x][y] = arr[y][x] = 1;
	}

	
	int min = 9999;
	int index = 0;
	// 2번 인덱스부터 시작하여 가장 작은 케빈 값을 min 에 저장
	for (int i = 1; i <= n; i++) {

		q.push(i);
		visit[i] = 1;

		// 현재 인덱스 i 의 케빈 결과 값이 더 작을 경우 min 에 해당 값을 저장 후 해당 인덱스를 저장
		int k = bfs(i);
		if (k < min) {
			min = k;
			index = i;
		}

		// 방문 값을 초기화
		for (int x = 1; x <= n; x++)
			visit[x] = 0;
	}

	cout << index;


	return 0;
}