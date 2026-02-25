#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int t;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;

		int w=0, b=0;
		string x, y;
		cin >> x >> y;

		for (int i = 0; i < x.size(); i++) {
			if (x[i] == y[i]) continue;
			
			if (x[i] == 'B') b++;
			else w++;
		}

		if (w > b) cout << w << '\n';
		else cout << b << '\n';
	}

	

	return 0;
}