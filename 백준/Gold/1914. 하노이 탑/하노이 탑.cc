#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int by, int to);
int main()
{
	// 원판의 개수를 x 에 입력
	int x;
	cin >> x;
	
	// hanoi 에서 원판의 개수가 x 개 일 때 이동횟수는 (2^x -1) 번
	// 20 이 넘어갈시 int 는 동작 x --> 문자로 변환하여 진행
	// pox 는 doulbe 형을 반환
	string  a = to_string(pow(2, x));

	int q = a.find('.'); // 정수 부분의 바로 뒤('.')의 인덱스를 q 에 저장
	a = a.substr(0, q); // 정수 부분만 문자열 a 에 다시 저장
	
	a[a.length() - 1] -= 1; // a 의 숫자를 1 감소

	cout << a << endl;

	// 원판의 개수가 20개 이하일 때만 진행
	if(x <=20 ) hanoi(x, 1, 2, 3);
} 

// n 읜 원판의 개수
void hanoi(int n, int from, int by, int to) {

	if (n == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(n - 1, from, to, by); // from 에 있는 n-1 개의 원판을 by 로 이동
		printf("%d %d\n", from,to);// from 에 있는 1개의 원판을 to 로 이동
		hanoi(n - 1, by, from, to);// by 에 있는 n-1 개의 원판을 to 로 이동
	}

}