#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
string s[101];

int isPal(string s) {

	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) return 0;
	}

	return 1;

}

int solve() {

	int k =0;
	cin >> k;

	string x;
	for (int i = 0; i < k; i++) {
		
		cin >> x;
		s[i] = x;
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {

			if (i == j) continue;

			if (isPal(s[i] + s[j])) {
				cout << s[i] + s[j] << '\n';
				return 1;
			}

		}
	}

	return 0;

}


int main(void) {

	cin >> n;
	while (n--) {
		int res=  solve();

		if (!res) cout << 0 << '\n';
	}
	
	return 0;
}