#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*
	백준: 11505 주식
*/

int t;
int d; // 날짜를 나타낼 변수 d

int main(void) {

	cin >> t;
	while(t--) {
		cin >> d;

		vector<int> v(d);

		// 날짜에 해당하는 주가를 입력
		for (int j = 0; j < d; j++) {
			cin >> v[j];
		}
		
		long long res = 0;
		int max_val = -1;
		// 마지막 날부터 검사하여 값을 계산
		for (int k = d - 1; k >= 0; k--) {
			max_val = max(max_val, v[k]);
			res += max_val - v[k];
		}

		cout << res << '\n';
		}

	return 0;
}