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

	// n 은 도시의 개수
	// m 은 여행할 도시들의 수
	int n, m;
	cin >> n >> m;

	// 각 원소의 부모 노드 값을 각 원소 값에 할당
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	int x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// x 에 1 이 입력될 시 i, j 는 연결된 요소로 판단 후 union 연산 진행
			// x 에 0 이 입력될 시 i, j 는 연결되어 있지 않음으로 판단
			cin >> x;
			if(x == 1) uni(i, j);

		}
	}
	

	// 시작 도시를 start 에 입력
	int start;
	cin >> start;
	
	int res = 1;
	for (int i = 1; i < m; i++) {

		cin >> x;
		// 두 도시가 속한 집합이 다를 경우 반복문 탈출 후 no 출력
		if (find(start) != find(x)) {
			res = 0;
			break;
		}
	}
	
	if (res) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}