#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N + 1);

	// 자신보다 왼쪽에 선 사람 중 키가 큰 사람의 수를 입력
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	vector<int> v(N + 1, 0);
	for (int i = 0; i < N; i++) {

		int x = arr[i]; 
		int count = 0; // 빈칸의 개수
		
		for (int j = 0; j < N; j++) {

			// 자리가 비어 있고
			if (v[j] == 0) {

				//  내 왼쪽에 나보다 큰 키가 있어야할 사람의 수와 빈칸의 개수가 동일한 경우
				if (count == x) {
					v[j] = i + 1;
					break;
				}
				count++;
			}
		}
	}

	// 결과 출력
	for (int i = 0; i < N; i++) {
		cout << v[i] << ' ';
	}

	return 0;
}