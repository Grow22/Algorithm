#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 0 ~ n 까지의 원소를 담을 벡터 v
vector<int> parent(1000000, 0);

// x 의 부모 노드를 찾는 연산
int find(int x) {


	// x 의 부모가 자신인 겨웅 루트 노드를 반환
	if (parent[x] == x) {
		return x;
	}
	// x 의 부모 노드를 찾지 못했을 경우 상위 노드로 이동하여 루트 노드를 찾기
	return parent[x] = find(parent[x]);
}

void uni(int x, int y) {

	int root1 = find(x);
	int root2 = find(y);

	// 두 개의 부모 노드 값이 다를 경우
	// root1 의 부모 루트 노드 값을 root2 로 변경
	if (root1 != root2) {
		parent[root1] = root2;
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// n 은 점의 개수
	// m 은 진행될 게임의 수
	int n, m;
	cin >> n >> m;

	// 각 원소의 부모 노드 값을 각 원소 값에 할당
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}


	vector<pair<int, int>>v;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));

	}

	
	int res = 0;
	for (int i = 0; i < m; i++) {

		// 두 정점이 다른 집합에 속하는 경우
		if (find(v[i].first) != find(v[i].second)) {
			uni(v[i].first, v[i].second);
		}
		// 두 정점이 같은 집합에 속하는 경우 ==> 사이클을 형성할 경우
		else {
			res = i+1;
			break;
		}

	}

	cout << res;

	

	return 0;
}