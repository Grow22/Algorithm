#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, find;
	cin >> n >> find;

	vector<vector<int>> v(n + 1, vector<int> (n+1));

	int number = n * n;
	int x = 1, y = 1;
	int resX, resY;
	// i 는 변의 개수, 한 바퀴 돌 때마다 변의 개수는 2 감소
	for (int i = n-1; i >0; i -= 2) {

		int cnt = 0;
		for (int j = 1; j <= i * 4; j++, number--) {
			v[x][y] = number;

			// 만약 원소를 발견했을 경우
			if (find == number) {
				resX = x;
				resY = y;
			}

			// cnt 값에 따라 방향 전환후 좌표 증가
			if (cnt == 0) x++; // 아래
			else if (cnt == 1) y++; // 오른쪽
			else if (cnt == 2) x--; // 위
			else if (cnt == 3) y--;  // 왼쪽

			// 한 변을 모두 돌았을 경우 방향 전환
			if (j % i == 0) cnt++;
		}
		// 한 변을 모두 돌았을 경우 안 쪽으로 이동
		x++, y++;
	}
	
	v[x][y] = number;
	if (find == number) {
		resX = x;
		resY = y;
	}

	// n * n 배열 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << resX << ' ' << resY;
	return 0;
}