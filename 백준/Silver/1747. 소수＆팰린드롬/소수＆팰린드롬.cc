#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int n;

bool checkPal(string s) {

	string a, b;

	a = s;
	reverse(s.begin(), s.end());
	b = s;

	// 뒤집은 두 문자열이 같을 경우
	if (a == b) return true;
	else return false;
}

// 소수인 지를 판별
bool isPrime(int n) {

	if (n < 2) return false;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;


	for (int i = n;; i++) {

		if (isPrime(i) && checkPal(to_string(i))) {
			cout << i;
			break;
		}
	}
	

	return 0;
}