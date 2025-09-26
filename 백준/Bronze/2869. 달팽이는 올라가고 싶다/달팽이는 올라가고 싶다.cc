#include <iostream>
using namespace std;
int main()
{
	int A; int B; int V;
	cin >> A >> B >> V;
	
	// (1) (A - B) 만큼의 거리를 이동했을 때 (V - A) 에 도달하는 일수를 count 에 저장
	int count = (V - A) / (A - B);

	// (2) (V - A) % (A - B) == 0 이면 count 값을 1증가
	// 하루만 더 이동하면 종료되기 때문
	if ((V - A) % (A - B) == 0) count++;
	// (2) - 1 그렇지 않은 경우 2 증가 
	// V - A 에 도달하지 못했기 때문
	else count += 2;

	cout << count;
} 