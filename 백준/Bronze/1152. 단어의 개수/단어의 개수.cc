#include <iostream>

#include <vector>
#include <string>
using namespace std;

int main() {

	string h;

	getline(cin, h);


	// 문자열의 길이가 1인 경우
	if (h[0] == ' ' && h.length() == 1) {
		cout << 0;
		return 0;
	}

	int res = 1; // 결과를 나타낼 변수 res
 	for (int i = 1; i < h.length() - 1; i++) {
		if (h[i] == ' ') res++;
	}

	cout << res;
	return 0;
}