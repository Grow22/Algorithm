#include <iostream>
using namespace std;
int main()
{
	
	int N; // N 은 주어진 수의 개수

	cin >> N;

	int x;
	int res = 0; // 소수의 개수를 나타낼 변수 res
	// (1) 입력받은 정수 N 만큼 반복
	for (int i = 0; i < N; i++) {

		// x 에 정수를 입력
		cin >> x;

		
		// 소수인지를 판별한 변수 r
		int r = 1;
		for (int j = 2; j < x; j++) {
			if (x % j == 0) {
				r = 0;
				break;
			}

		}
		
		// 소수라면 r == 1 
		if (r == 1 && x != 1) res++;

	}
	cout << res;
} 