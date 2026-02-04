#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, s;
vector<int> v(21);
int res;
// num 은 살펴볼 범위의 초기 인덱스
// sum 은 앞에서부터 살펴본 배열의 합
void func(int num, int sum) {

	// 마지막까지 전부 배열의 값들을 살펴보았을 때 합이 같은 경우
	if (num == n) {
		if (sum == s) {
			res++;
		}
		return;
	}

	// 현재 값을 더한 상태와 그렇지 않은 상태를 재귀 진행
	func(num + 1, sum);
	func(num + 1, sum + v[num]);
}

int main(void) {

	// n 은 선택할 정수의 개수
	// s 는 만들어야 합 합
	cin >> n >> s;

	// 정수의 개수를 입력
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// 함수 진행
	func(0, 0);

	if (s == 0) res--;

	cout << res;

	return 0;
}