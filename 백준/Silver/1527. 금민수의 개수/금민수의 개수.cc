#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b;
long long res;
void solve(long long n) {

	// 범위를 벗어날 경우
	if (n > b)  return;

	// 범위에 포함될 경우
	if (a <= n && n <= b) res++;

	solve(10 * n + 4);
	solve(10 * n + 7);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;


	solve(4);
	solve(7);

	cout << res;

	return 0;
}