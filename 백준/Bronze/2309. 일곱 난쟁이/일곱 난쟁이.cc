#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int arr[9];
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}


	// 난쟁이들의 키를 정렬
	sort(arr, arr + 9);

	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			// 두 난쟁이의 키를 뺐을 때 값이 100 인 경우
			if (sum - arr[i] - arr[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) {
						continue;
					}
					cout << arr[k] << endl;
				}
				return 0;
			}
			
		}
	}
	return 0;
}