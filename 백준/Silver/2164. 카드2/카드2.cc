#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;


// 정답은 맞으나 시간 초과
int main(void) {

	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int x;

	cin >> x;

	queue<int> q;
	// x 만큼 원소 push
	for (int i = 1; i <= x; i++) {
		q.push(i);
	}

	// 큐의 사이즈가 1보다 클 동안 반복
	while (q.size() > 1) {
		
		// 1. 맨 위의 원소를 pop()
		q.pop();

		// 2. 맨 위의 원소를 맨 아래로 이동 
		q.push(q.front());

		// 3. 맨 위의 원소를 제거
		q.pop();
	}

	cout << q.front();
	
	
	return 0;
}