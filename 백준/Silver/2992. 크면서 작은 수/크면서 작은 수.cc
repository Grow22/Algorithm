#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;

int main(void) {

	// 문자열 s 를 입력
	cin >> s;

	// 입력받은 정수의 다음 순열 값이 존재할 경우 해당 값을 출력
	// 해당 값이 가장 큰 정수일 경우 0 을 출력
	if (next_permutation(s.begin(), s.end()))  cout << s;
	else cout << 0;
	

}