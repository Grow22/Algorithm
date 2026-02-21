#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[2001];
int visit[2001];

int res;

void dfs(int x, int dis) {
	
	// 경로가 4 인 관계를 발견했을 경우
	if (dis == 4) {
		res = 1;
		return;
	}
	visit[x] = 1;

	for (int next : adj[x]) {
		if (!visit[next]) {
			dfs(next, dis + 1);
			if (res) return;
		}
	}

	visit[x] = 0;
}

int main() {

	cin >> n >> m;

	// m 개의 관계의 수를 입력
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		dfs(i, 0);
		// 길이가 4 인 관계를 발견했을 경우 
		if (res) break;
	}

	cout << res;

	return 0;

}