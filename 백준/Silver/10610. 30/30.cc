#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

string s;


int main(void) {

	cin >> s;

	
	sort(s.begin(), s.end(), greater<char>());
	if (s[s.size() - 1] != '0') {
		cout << -1;
		return 0;
	}

	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
	}

	if (sum %3 != 0) {
		cout << -1;
		return 0;
	}
	
	cout << s;

	return 0;
}