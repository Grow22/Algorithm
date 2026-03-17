#include <iostream>
#include <vector>

using namespace std;

// 5*5 숫자판을 의미
int map[5][5];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[1000000];

int res;

// sum 은 문자 합을 의미
void dfs(int x, int y, int sum, int depth) {

	// 만약 6 자리 길이의 정수를 탐색하였을 경우
	if (depth == 5) {
	
		if (visit[sum] == false) {
			visit[sum] = true;
			res++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {

		int X = x + dx[i];
		int Y = y + dy[i];

		if (X >= 0 && X < 5 && Y >= 0 && Y < 5) {
			dfs(X, Y, sum * 10 + map[X][Y], depth + 1);
		}
		// 만약 문자열이 나오지 않은 경우
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, map[i][j], 0);
		}
	}

	cout << res;
	return 0;
}
