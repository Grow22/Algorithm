#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(void) {

	// N 은 동전의 종류
	// K 는 만들어야할 가치의 합
	int N, K;

	cin >> N >> K;
	
	vector<int> list;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		list.push_back(x);
	}

	// 동전의 개수를 cnt 변수에 저장
	int cnt = 0;

	// 가장 큰 동전의 가치부터 반복문을 돌며
	for (int i = N - 1; i >= 0; i--) {
		// K 보다 동전의 가치가 작거나 같을 경우
		if (list[i] <= K) {
			cnt += K / list[i];
			K %= list[i];
		}
	}
	cout << cnt;

	return 0;
}