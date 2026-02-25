#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;

vector<pair<string, int>> v;
string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;

	string s;
	for (int i = m; i <= n; i++) {

		if (i >= 10) {
			s = nums[i / 10] + " " + nums[i % 10];
		}
		else {
			s = nums[i % 10];
		}
		v.push_back(make_pair(s,i));
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {

		cout << v[i].second << " ";
		if (i % 10 == 9) cout << '\n';
	}

	return 0;
}