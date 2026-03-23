#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define max_num	236196
// n 은 시작 정수
// p 는 곱하는 횟수
int n, p;

int res; // 결과를 나타낼 변수

// 나온 정수의 방문 여부를 나타낼 배열 visit
int visit[max_num]; 

void dfs(int x) {
 
	int origin = x; // 원래 값을 나타낼 변수 origin
	int next = 0; // 다음 정수를 나타낼 변수 next

	visit[x - 1]++; // 방문 횟수를 1 증가

	// 다음으로 이동할 값을 계산
	while (x > 0) {
		next += pow(x % 10, p);
		x /= 10;
	}

	// 만약 반복되는 값일 경우(==2) 종료
	if (visit[next - 1] == 2) return;

	dfs(next); // 다음 구간 탐색 진행

	// 탐색이 끝났을 대 반복되는 구간이 아닌 경우 res 증가
	if (visit[origin - 1] == 1) res++;
}

int main(void) {
	
	cin >> n >> p;
	dfs(n);

	cout << res;

	return 0;
}