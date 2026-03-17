#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int arr[30][30];

// 선택한 치킨의 인덱스를 나타낼 배열 pick
int pick[3];

int res;

void solve(int idx, int cnt) {

	// 아직 치킨을 다 선택하지 않은 경우
	if (cnt != -1) {
		pick[cnt] = idx;
	}

	// 치킨을 모두 선태하였을 경우(3개)
	if (cnt == 2) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int score = 0;
			for (int j = 0; j < 3; j++) {
				score = max(arr[i][pick[j]], score);
			}
			sum += score;
		}
		res = max(res, sum);
		return;
	}
	
	// idx 를 통해 치킨의 수를 선택
	for (int i = idx; i < m; i++) {
		solve(i + 1, cnt+1);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	// m 개에 대한 치킨의 선호도를 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	solve(-1, -1);

	cout << res;
	return 0;

}