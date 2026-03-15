#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v(20);
bool range[20 * 100000+1];

// idx 는 인덱스, sum 은 합을 의미
void solve(int idx, int sum) {

	// 모든 원소에 대한 탐색을 마쳤을 경우 range 에 값을 기록
	if (idx == n) {
		range[sum] = true;
		return;
	}

	solve(idx + 1, sum + v[idx]);
	solve(idx + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	// n 개의 원소를 입력
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	solve(0, 0);

	int start = 1;
	while (1) {

		// 합에 해당하지 않은 값을 발견했을 경우
		if (range[start] == 0) {
			cout << start;
			break;
		}
		start++;
	}
	return 0;
}