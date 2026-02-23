#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[1024];
vector<int> v[10];
int k;


void solve(int depth, int start, int end) {

	if (start >= end) return;
	
	int mid = (start + end) / 2;
	
	v[depth].push_back(arr[mid]);
	solve(depth + 1, start, mid);
	solve(depth + 1, mid + 1, end);
}

int main(void) {

	cin >> k;

	// 원소들 입력
	for (int i = 0; i < pow(2, k) - 1; i++) {
		cin >> arr[i];
	}

	solve(0, 0, pow(2, k) - 1);

	for (int i = 0; i < k; i++) {
		for (auto num : v[i]) {
			cout << num << ' ';
		}
		cout << '\n';
	}
	return 0;
}