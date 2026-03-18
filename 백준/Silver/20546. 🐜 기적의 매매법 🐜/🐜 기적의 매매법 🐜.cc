#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 가지고 있는 돈을 입력
	int money;
	cin >> money;

	// 준현이와 성민이에게 10000 원씩 배정
	int jun = money;
	int sung = money;

	int jun_stock = 0;
	int sung_stock = 0;

	// 14일 간의 주식 가격을 입력
	int arr[14];
	for (int i = 0; i < 14; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < 14; i++) {

		if (jun >= arr[i]) {
			
			jun_stock += jun / arr[i];
			jun -= arr[i] * jun_stock;
		}
	}
	
	// 성민이의 가격을 계산
	for (int i = 3; i < 14; i++) {

		// 3일 연속 가격이 상승하는 경우 전량 매도
		if ((arr[i] > arr[i - 1]) && (arr[i-1] > arr[i - 2]) && (arr[i-2] > arr[i-3])) {
			sung += arr[i] * sung_stock;
			sung_stock = 0;

		}
		// 3 일 연속 가격이 하락하는 경우 전량 매도
		else if (arr[i] < arr[i - 1] && (arr[i-1] < arr[i-2] && arr[i-2] < arr[i-3])) {
			
			sung_stock += sung / arr[i];
			sung %= arr[i];
		}
	}
	
	// 준현이가 가지고 있는 자산을 계산	
	int jun_res = jun + jun_stock * arr[13];

	// 성민이가 가지고 있는 자산을 계산
	int sung_res = sung + sung_stock * arr[13];

	if (jun_res > sung_res) cout << "BNP";
	else if (jun_res < sung_res) cout << "TIMING";
	else cout << "SAMESAME";

	return 0;
}