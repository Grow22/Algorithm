#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 0 ~ n 까지의 원소를 담을 벡터 v
vector<int> parent(1000000,0);

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

	// n 은 원소의 개수
	// m 은 연산의 횟수
	int n, m;
	cin >> n >> m;

	// 각 원소의 부모 노드 값을 각 원소 값에 할당
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}


	vector<string> res;
	int op, x, y;
	// m 만큼의 연산횟수를 진행
	for (int i = 0; i < m; i++) {
		cin >> op;
		cin >> x >> y;
		// op 값이 1 인 경우 find 연산을 진행
		if (op)
		{
			int root1 = find(x);
			int root2 = find(y);
			// 두 노드의 집합이 같은 집합일 경우 YES 출력
			if (root1 == root2) {
				res.push_back("YES");
			}
			// 두 노드의 집합이 다를 경우 NO 출력
			else {
				res.push_back("NO");
			}

		}
		// x 값이 0 인 경우 union 연산을 진행
		else {
			uni(x, y);
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}

	return 0;
}