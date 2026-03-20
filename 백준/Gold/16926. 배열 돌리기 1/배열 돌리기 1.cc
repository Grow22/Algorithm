#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// n*m, r 은 로테이션 횟수
int n, m, r;


// 오른쪽,아래,왼쪽,위
int dx[4] = {0,1, 0,-1 };
int dy[4] = {1,0,-1,0 };

int arr[300][300];

void move(int box) {

	// i 는 각 박스의 시작 지점
	// ex) i  = 0 -> 해당 박스의 시작 지점 == (0,0)
	for (int i = 0; i < box; i++) {

		int start = arr[i][i];
		
		// 시작 지점은 (i,i)
		int x = i;
		int y = i;

		int k = 0;
		// 4 방향으로 이동 진행
		while (k < 4) {

			// (X,Y) 지점을 -> (x,y) 좌표로 이동
			int X = x + dx[k];
			int Y = y + dy[k];
			
			// 시작 지점으로 돌아올 경우 탈출
			if (i == X && i == Y) break;
			// 범위 안에 있을 경우 원소를 이동
			if (X < n - i && i <= Y && Y < m - i) {
				arr[x][y] = arr[X][Y];
				x = X;
				y = Y;
			}
			// 범위를 벗어날 경우 원소를 이동시킬 방향 전환
			else {
				k++;	
			}
		}
		// 마지막 원소 이동
		arr[i + 1][i] = start;
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int box = min(n, m) / 2;

	for (int i = 0; i < r; i++) {
		move(box);
	}


	// 결과 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}