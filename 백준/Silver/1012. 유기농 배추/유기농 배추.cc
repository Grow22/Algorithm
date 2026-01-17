#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int M, N;
// 상, 하, 좌, 우로 이동하기 위한 좌표배열 xx,yy 
int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0 };

// 배추가 심어지는 위치를 나타낼 배열 arr
int arr[50][50];

void dfs(int x, int y) {

	// dfs 시작할 배추의 위치의 값을 0 으로 변경
	arr[x][y] = 0;

	// 상, 하, 좌, 우 로 이동하며 배추가 있는 지를 검사
	for (int i = 0; i < 4; i++) {
		int X = x + xx[i];
		int Y = y + yy[i];

		// 만약 근방에 배추가 심어져 있는 경우 해당 값을 0 으로 변경 후 dfs 진행
		if ((X >= 0 && X < N) && (Y >= 0 && Y <M) && arr[X][Y] == 1) {
			arr[X][Y] = 0;
			dfs(X, Y);
		}
	}

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	// 테스트 케이스 T
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {

		// 가로 길이 M
		// 세로 길이 N
		cin >> M >> N;

		// 심어지는 배추의 개수 K
		int K;
		cin >> K;

		int a,b;
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			arr[b][a] = 1;
		}
		
		// 필요한 지렁이의 개수를 나타낼 변수 res
		int res = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (arr[x][y] == 1) {
					dfs(x, y);
					res++;
				}
			}
		}
		cout << res << '\n';
	}

	return 0;

}