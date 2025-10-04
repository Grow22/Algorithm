#include <iostream>
#include <algorithm>
using namespace std;
#define Max 1000

int main() {

	int arr[Max];
	// 입력받을 정수의 개수를 입력
	int N;
	cin >> N;

	// N 만큼의 정수를 배열 arr 에 저장
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}
	return 0;


}