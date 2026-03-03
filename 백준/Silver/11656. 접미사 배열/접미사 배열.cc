#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s;
vector<string> v;
int main(void) {

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		
		string tmp = s.substr(i);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}