#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string a, b, c;

void solve() {

	sort(a.begin(), a.end());


	string res = "-1";

	int intB = stoi(b);

	do {

		// a 의 첫 문자가 0 일 경우 다음 순열 진행
		if (a[0] == '0') continue;

		// A 의 문자열의 길이가 더 길 경우 반복문 탈출
		if (a.length() > b.length()) break;
		 
		int intA = stoi(a);

		// B 보다 작은 지를 확인
		if (intA < intB) {
			res = a;
		}
		// a 가 b 보다 커질 경우 반복문 탈출
		else {
			break;
		}

	} while (next_permutation(a.begin(), a.end()));

	cout << res;
}

int main() {

	cin >> a >> b;

	solve();

	return 0;

}