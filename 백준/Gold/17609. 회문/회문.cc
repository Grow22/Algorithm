#include<iostream>
#include<string>
using namespace std;

string a;
int cnt = 0;

int isPalindrom(int left, int right, int cnt) {
	if (cnt == 2) return 2;

	while (left < right) {
		if (a[left] == a[right]) {
			left++;
			right--;
		}
		else {
			if (isPalindrom(left + 1, right, cnt + 1) == 2 && isPalindrom(left, right - 1, cnt + 1) == 2) {
				return 2;

			}
			else return 1;
		}

	}

	if (cnt == 0) return 0;
	else return 1;

	
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T;
	int left, right;
	cin >> T;
	while (T--) {
		cin >> a;
		left = 0;
		right = a.length() - 1;

		cout << isPalindrom(left, right, cnt) << "\n";

	}
	return 0;
}