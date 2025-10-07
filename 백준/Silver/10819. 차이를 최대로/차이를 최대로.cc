#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	vector<int> v; // 결과를 저장할 배열 arr
	int N; // count of element 
	int result = -100 ; // 결과를 출력할 배열
	cin >> N;

	int x;
	// enter num in array
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());

	int sum = 0; // 각 결과의 합을 저장할 변수 sum
	// 모든 경우의 수를 돌며 최대값을 계산
	while (next_permutation(v.begin(), v.end())) {

		sum = 0;
		// 배열의 원소들의 합을 저장
		for (int i = 0; i < v.size() -1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}

		result = max(result, sum);
	}

	cout << result;
	
	return 0;
}