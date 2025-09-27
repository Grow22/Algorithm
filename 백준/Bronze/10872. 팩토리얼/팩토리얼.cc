#include <iostream>
using namespace std;
int main()
{
	int x;

	cin >> x;

	
	if (x == 0) {
		cout << '1';
		return 0;
	}
	int res = 1;
	// x 만큼 반복문을 돌면서
	for (int i = 1; i <= x; i++) {
		res *= i;
	}

	cout << res;
} 