#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {

	// 테스트 케이스 수를 변수 n 에 입력
	int n;

	cin >> n;

	int c = 0;
	string s1;
	string s2;

	
	for (int i = 0; i < n; i++) {

		int res = 1;
		// 의상의 개수를 나타내는 변수 c
		cin >> c;
		map <string, int> list;

		
		// 의상 종류에 따른 개수를 list 에 저장
		for (int j = 0; j < c; j++) {
			cin >> s1;
			cin >> s2;
			list[s2]++;
		}
		
		// 변수 res 에 각 (의상의 종류 별 개수 + 1(해당 의상을 입지 않은 경우)) 값을 곱함
		for (auto x : list) {
			res *= x.second +1;
		}

		// 각 케이스에서 어느 의상도 입지 않은 경우 1을 뺀 후 결과 출력
		cout << res -1 << '\n';
	}
	return 0;
}