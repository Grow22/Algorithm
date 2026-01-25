#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v(M + 1,0);
	v[1] = 1;

	for (int i = 2; i*i <= M; i++) {

		// 인덱스 i 의 정수 값에 할당된 값이 1 인 경우 다음 정수를 진행
		if (v[i] == 1) continue;

		//  i * i 부터 i 값씩 더하며 반복문을 진행하면서
		for (int j = i * i; j <= M; j += i) {
			// 할당된 값이 0 인 소수에서 제외시킴
			if (v[j] == 0) v[j] = 1;
		}
	}

	for (int i = N; i <= M; i++)
	{
		if (v[i] == 0) cout << i << '\n';
	}

	return 0;
}