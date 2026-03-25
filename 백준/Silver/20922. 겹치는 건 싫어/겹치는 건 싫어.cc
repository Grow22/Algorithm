#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// n 은 원소의 수
// k 는 넘어선 안 될 최대 원소의 개수
int n, k;

int arr[100001]; // 현재까지 나온 정수들의 값을 저장 
vector<int> v;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	// 원소 입력
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x; 
		v.push_back(x);
	}

	// 두 개의 포인터로 나타낼 변수 left, right
	int left = 0;
	int right = 0;
	int res = 0;

	// 범위 안에 있을 동안만 반복
	while (right < n) {

		// right 가 가리키는 포인터의 값을 증가
		arr[v[right]]++;

		// right 가 가리키는 값의 수가 k 개 를 넘어갔을 경우
		while (arr[v[right]] > k) {
			arr[v[left]]--;
			left++;
		}

		// 거리 갱신
		res = max(res, right - left + 1);
		
		// right 포인터 오른쪽으로 한 칸 이동
		right++;
	}

	cout << res;

	return 0;
}