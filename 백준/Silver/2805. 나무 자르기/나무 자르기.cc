#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	
	int N, M; // 자를 나무의 개수: N개, 잘라서 더한 나무들의 최소합: M

	cin >> N >> M;

	vector<int> arr;

	int x;
	// 나무들의 길이를 입력
	for (int i = 0; i < N; i++) {
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());


	int low = 0;
	int high = arr[N-1];
	int result = 0;

	while (low <= high) {

		long long sum = 0;
		// 자를 나무의 길이를 mid 에 저장
		long long mid = (low + high)/2;

		// 자를 높이보다 나무의 길이가 길다면 남는 길이를 sum
		for (int i = 0; i < N; i++) {
			if (arr[i] - mid > 0) sum += arr[i] - mid;
		}

		// 길이가 부족하다면
		// 자를 높이의 길이를 감소
		if (sum < M) {
			high = mid - 1;
		}

		// 길이가 M 보다 크다면
		// 높이의 범위를 감소
		else {
			low = mid + 1;
			result = mid;
		}
	}

	cout << result;
	return 0;
}