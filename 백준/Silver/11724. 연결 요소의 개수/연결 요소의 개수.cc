#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int list[10000][10000];
int visited[10000];

// 노드 개수 n, 엣지 개수 e 를 입력받음
int n, e;

void dfs(int x) {

	visited[x] = true;


	for (int i = 1; i <= n; i++) {
		
		if (x != i) {
			if (list[x][i] && !visited[i]) {
				dfs(i);
			}
		}
	}
}

int main(void) {


	cin >> n >> e; 

	// 입력받은 간선의 개수 e 만큼 간선 입력
	int x, y;
	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		list[x][y] = 1;
		list[y][x] = 1;
	}

	// connected component 를 저장할 변수 cnt
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}