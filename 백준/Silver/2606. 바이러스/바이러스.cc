	#include <iostream>
	#include <stdio.h>
	#include <algorithm>
	#include <vector>
	#include <map>
	using namespace std;

	int list[101][101];
	int visited[101];
	int res;

	void dfs(int x) {

		visited[x] = true;

	
		for (int i = 0; i < 101; i++) {
			if (list[x][i] && !visited[i]) {
				res++;
				dfs(i);
			}
		}
	}

	int main(void) {

		int n, e;

		cin >> n >> e;

		int x, y;
		for (int i = 0; i < e; i++) {
			cin >> x >> y;
			list[x][y] = 1;
			list[y][x] = 1;
		}

		dfs(1);

		cout << res;

		return 0;
	}