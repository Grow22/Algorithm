#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int n;
// 단지 번호를 나타낼 배열 list
int list[25][25];

// 상, 하, 좌, 우로 이동하기 위한 좌표배열 xx,yy 
int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };

// 방문한 단지 수를 나타낼 변수 res
int res = 0;

void dfs(int x, int y) {

	list[x][y] = 0;
	res++;
	for (int i = 0; i < 4; i++) {
		int X = x + dr[i];
		int Y = y + dc[i];

		if ((X>=0 && X < n) && (Y >=0 && Y < n) && list[X][Y] == 1) {
			dfs(X, Y);
		}
	}
	
}

int main(void) {
	
	// n * n 을 표현할 변수 n
	cin >> n;

	// n*n 단지만큼 입력
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {

			if (s[j] == '1') {
				list[i][j] = 1;
			}
			else list[i][j] = 0;
		}
	}
	

	vector<int> v;
	// 총 단지 수를 나타낼 변수 cnt
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (list[i][j] == 1) {
				res = 0;
				cnt++;
				dfs(i, j);
				v.push_back(res);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (int i = 0; i < v.size()-1; i++) {
		cout << v[i] << '\n';
	}
	cout << v[v.size() - 1];

	return 0;
}