#include <iostream>
#include <vector>

using namespace std;


// 출력할 최대 기쁨의 수치
int max_pleasure;
int n;

vector<int> l;
vector<int> j;

// idx 는 인덱스, strong 는 체력, pleasure 는 기쁨
void solve(int idx, int hp, int pleasure) {

	if (hp <= 0) return;

	// 모든 탐색을 끝마쳤을 경우 현재 기쁨이 최대 기쁨보다 값이 클 경우
	if (idx == n) {
		if (max_pleasure < pleasure)
			max_pleasure = pleasure;
		return;
	}

	// 현재 인덱스 값을 포함한 경우와 그렇지 않은 경우
	solve(idx + 1, hp - l[idx], pleasure + j[idx]);
	solve(idx + 1, hp, pleasure);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;


	int x;
	// 체력 입력
	for (int i = 0; i < n; i++) {
		cin >> x;
		l.push_back(x);
	}

	// 기쁨 입력
	for (int i = 0; i < n; i++) {
		cin >> x;
		j.push_back(x);
	}

	solve(0, 100, 0);
	cout << max_pleasure;
	return 0;
}