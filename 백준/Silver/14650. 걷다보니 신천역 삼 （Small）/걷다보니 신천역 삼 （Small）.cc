#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;

int main(void) {

	cin >> n;

	// 처음 올 수 있는 자리는 1,2 를 감안하여 2 로 시작
	int res = 2; 


	if (n == 1) cout << 0;
	else if (n == 2) cout << 2;
	// 세 자리 이상인 경우
	else {

		for (int i = 0; i < n - 2; i++) {
			res *= 3;
		}
		cout << res;
	}

	return 0;
}