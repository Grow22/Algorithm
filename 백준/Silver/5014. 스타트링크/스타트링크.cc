#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


/*
	백준 5014: 스타트링크
*/


int F, S, G, U, D;


queue<pair<int,int>> q;
vector<int> visit(1000001);

void bfs(int x) {

	q.push(make_pair(x,0));
	visit[x] = 1;
	
	int cnt= 0;
	while (!q.empty()) {

		pair<int,int> v = q.front();
		q.pop();

		int cur = v.first;
		int cnt = v.second;

		// 목표로 하는 층 G 에 도달하였을 경우
		if (cur == G) {
			cout << cnt;
			return;
		}

		// up 의 값이 아직 큐에 없고 최고층의 범위 안에 있을 경우
		int up = v.first + U;
		if ((up >= 1 && up <= F) && !visit[up]) {
			visit[up] = 1;
			q.push(make_pair(up, cnt + 1));
		}

		// down 의 값이 아직 큐에 없고 최고층의 범위 안에 있을 경우
		int down = v.first - D;
		if ((down >= 1 && down <= F) && !visit[down]) {
			visit[down] = 1;
			q.push(make_pair(down,cnt +1));
		}

		
	}

	// 큐가 빌 때동안 G 에 도달하지 못하였을 경우
	cout << "use the stairs";

	return;

}

int main(void) {

	cin >> F >> S >> G >> U >> D;


	bfs(S);

	return 0;
}