#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(void) {

	int N, M;


	// 결과를 나타낼 vector res
	vector<string> res; 

	// 듣도 못한 사람의 이름을 저장할 map list
	map<string, bool> list;


	cin >> N >> M;

	string sr;
	// 듣도 못한 사람의 이름을 list 에 저장
	for (int i = 0; i < N; i++) {
		
		cin >> sr;
		list.insert(make_pair(sr, true));
	}

	int cnt = 0;
	// 보도 못한 사람의 이름을 입력
	for (int i = 0; i < M; i++) {
		cin >> sr;
		// map 에 중복되는 단어가 있을 경우 해당 단어를 res 에 저장
		if (list[sr]) {
			res.push_back(sr);
			cnt++;
		}
	}

	cout << cnt << '\n';
	// 중복되는 이름이 저장된 res 를 사전순으로 정렬
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		if (i == res.size() - 1) {
			cout << res[i];
		}
		else cout << res[i] << '\n';
	}
	return 0;
}