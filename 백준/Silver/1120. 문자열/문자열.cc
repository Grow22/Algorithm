#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

string a, b;

int res;
int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;
	
	int diff = b.length() - a.length();

	int min = 9999;
	for (int i = 0; i <= diff; i++) {

		int x = 0;
		for (int j = 0; j < a.length(); j++) {

			if (a[j] != b[i + j]) {
				x++;
			}
		}

		if (min > x) {
			min = x;
		}
	}
	cout << min;
}