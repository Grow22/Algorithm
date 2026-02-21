#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string a;
int res;

void solve() {


	sort(a.begin(), a.end());

	int size = a.size();
	do {

		int t = 1;
		for (int i = 1; i < size; i++) {
			if (a[i] == a[i-1])
			{
				t = 0;
				break;
			}
		}

		if (t) res++;
	} while (next_permutation(a.begin(), a.end()));

	cout << res;
}

int main() {

	cin >> a;

	solve();

	return 0;

}