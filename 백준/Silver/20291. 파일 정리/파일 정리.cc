#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n;
map<string, int> m;

int main(void) {

	cin >> n;

	string tmp;
	for (int i = 0; i < n; i++) {

		cin >> tmp;

		int index = tmp.find(".");

		string sub = tmp.substr(index + 1, tmp.size());
		
		// 확장자에 해당하는 숫자를 증가
		m[sub]++;
	}
	
	for (auto res : m) {
		cout << res.first << " " << res.second << '\n';
	}

	return 0;
}