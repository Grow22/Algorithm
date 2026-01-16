#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {
	
	// 타일의 길이를 변수 n 에 입력
	int n; 
	cin >> n;

	vector<int> p(n+1);

	p[1] = 1;
	p[2] = 2;
	for (int i = 3; i <= n; i++) {
		p[i] = (p[i - 1] + p[i - 2]) % 10007;
	}

	int res = p[n];

	cout << res;

	return 0;
}