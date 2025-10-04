#include <iostream>
#include <algorithm>
using namespace std;

int cmp(string a, string b) {

	// 1. if a.length is equal b.length
	// compare word alpabetical
	if (a.length() == b.length()) {
		return a < b;
	} 
	// 2. compare length a and b
	else {
		return a.length() < b.length();
	}
}

int main() {

	string arr[20000];
	// 입력받을 정수의 개수를 입력
	int N;
	
	cin >> N;
	// 단어를 배열에 입력
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 배열을 정렬
	sort(arr, arr + N, cmp);

	// 중복된 것을 제외하고결과 출력
	for (int i = 0; i < N; i++) {
		if (arr[i] == arr[i - 1]) {
			continue;
		}
		cout << arr[i] << endl;
	}

	return 0;
}