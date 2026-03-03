#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s;

int gcd(int a, int b) {

	if (a < b) {
		return gcd(b, a);
	}
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(void) {

	cin >> s;

	int n = stoi(s.substr(0, s.find(":")));
	int m = stoi(s.substr(s.find(":") + 1, s.size()));
	
	int x = gcd(n,m);

	n /= x;
	m /= x;

	cout << n << ":" << m;


	return 0;
}