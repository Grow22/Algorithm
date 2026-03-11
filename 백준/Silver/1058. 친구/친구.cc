#include <iostream>
#include <queue>

using namespace std;

char arr[50][50];

int visit[50];
int num;
int max_friends = 0;
void bfs(int x) {

	int depth = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(x, depth));
	visit[x] = 1;
	int friends = 0;
	
	// 큐가 빌 때 동안 반복
	while (!q.empty()) {
		

		pair<int, int> v = q.front();
		q.pop();
		int now_v = v.first;
		int depth = v.second;
		// depth 값이 2 이상일 경우 다음 비교
		if (depth > 1) continue;
		for (int i = 0; i < num; i++) {

			if (i != x && !visit[i] && arr[now_v][i] == 'Y') {
				q.push(make_pair(i, depth+1));
				visit[i] = 1;
				friends++;
			}
		}
	}

	if (friends > max_friends) max_friends = friends;
}

void reset() {
	for (int i = 0; i < num; i++) {

		visit[i] = 0;
	}
}

int main() {

	cin >> num;

	char c;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < num; i++) {
		bfs(i);
		
		// visit 배열을 초기화
		reset();
	}

	cout << max_friends; 
}