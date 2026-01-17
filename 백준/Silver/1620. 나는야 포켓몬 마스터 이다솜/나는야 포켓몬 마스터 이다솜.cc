#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	// 포켓몬 이름과 순번을 dic 에 저장
	map<string, int> dic;
	vector<string> name(N+1);
	string n;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		dic[n] = i;
		name[i] = n;
	}

	string search;
	for (int i = 0; i < M; i++) {
		cin >> search;
		// 입력받은 문자열이 정수일 경우 
		// 정수에 해당하는 포켓몬 이름을 출력
		if (isdigit(search[0])) {
			cout << name[stoi(search)] << '\n';
		}
		// 입력받은 문자열이 이름일 경우
		// 도감에서의 순서를 출력
		else {
			cout << dic[search] << '\n';
		}
}
	return 0;
	}