#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
string res;
bool finish;

void solve(string temp, int cnt) {


	// 좋은 순열을 발생했을 경우
	if (finish) {
		return;
	}
	int size = temp.size();

	// 나쁜 순열이 발견될 경우 return
	for (int i = 1; i <= size / 2; i++) {
		if (temp.substr(size - i, i) == temp.substr(size - i * 2, i)) return;
	}

	// 첫 좋은 순열을 발견했을 경우
	if (cnt == N) {
		finish = true;
		res = temp;
		return;
	}

	// 다음 자리로 이동
	for (int i = 1; i <= 3; i++) {
		solve(temp + to_string(i), cnt + 1);
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	solve("", 0);
	cout << res;

	return 0;
}