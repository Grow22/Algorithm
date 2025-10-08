	#include <iostream>
	#include <algorithm>
	#include <vector>
	using namespace std;

	int main() {
	
		// N -> 집의 개수
		// C -> 공유기 개수
		int N, C;

		// 집, 공유기의 개수를 입력
		cin >> N >> C;

		vector<int> arr;

		int x;
		for (int i = 0; i < N; i++) {
			cin >> x;
			arr.push_back(x);
		}

		// vector 를 정렬
		sort(arr.begin(), arr.end());

		// 시작, 끝 거리를 low, high 로 설정
		int low = 1;
		int high = arr[N - 1];
	
		int result = 0;
	
		while (low <= high) {

			// 공유기를 설치할 길이를 mid 값으로 설정
			int mid = (low + high) / 2;

			// prev 는 공유기를 설치한 위치
			int prev = arr[0];
			int cnt = 1;
			// 반복문을 돌면서
			for (int i = 1; i < N; i++) {
			
				// 만약 공유기를 설치 가능하다면
				if (arr[i] - prev >= mid) {
					cnt++;
					prev = arr[i];
				}
			}
		
			// 공유기를 설치할 수 있는 수가 C 보다 크면
			// low 값을 증가
			if (cnt >= C) {

				result = max(result, mid);
				low = mid + 1;
			}
			// 공유기를 설치할 수 있는 수가 C 보다 작은 경우
			// high 값을 감소시켜 공유기의 설치 가능 길이(mid) 값을 감소
			else {
				high = mid - 1;
			}
		}
	
		cout << result;

		return 0;
	}