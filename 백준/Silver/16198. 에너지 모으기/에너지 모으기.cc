#include <iostream>
#include <vector>
using namespace std;

int n;

int res = -9999999;

void solve(vector<int> v, int sum) {

	// 구슬이 2개만 남았을 경우
	if (v.size() == 2) {
		if (res < sum) res = sum;
		return;
	}

	for (int i = 1; i < v.size() - 1; i++) {

		int ene = v[i - 1] * v[i + 1];

		vector<int> tmp = v;
		tmp.erase(tmp.begin() + i);
		solve(tmp, sum + ene);
	}
}

int main() {

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	solve(v, 0);
	cout << res;

	return 0;

}