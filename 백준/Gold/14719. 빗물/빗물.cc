#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// h 는 세로 길이, w 는 가로 길이
int h, w;
int res;
int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> h >> w;

	// w 크기 만큼 높이를 입력
	vector<int> v(w);
	for (int i = 0; i < w; i++) {
		cin >> v[i];
	}

	// 양 끝을 제외 후 빗물의 양을 검사
	for (int i = 1; i < w-1; i++) {
		
		int left = 0;
		int right = 0;
		for (int j = 0; j < i; j++) left = max(left, v[j]);
		for (int k = w - 1; k > i; k--) right = max(right, v[k]);

		res += max(0, min(left, right) - v[i]);
	}
	cout << res;
	return 0;
}