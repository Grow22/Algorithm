#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int main(void) {


	// N 은 사이트, 비밀번호 쌍의 개수
	// M 은 찾아야 하는 비밀번호의 개수
	int N, M;
	cin >> N >> M;

	map<string, string> list;
	string site;
	string pass;

	// site, password 를 list 에 저장
	for (int i = 0; i < N; i++) {
		cin >> site >> pass;
		list[site] = pass;
	}

	vector<string> res;
	string x;
	// 변수 M 의 개수에 따라 사이트에 맞는 패스워드를 출력
	for (int i = 0; i < M; i++) {
		cin >> x;
		res.push_back(list[x]);
	}

	// 결과 출력
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}
	return 0;
}