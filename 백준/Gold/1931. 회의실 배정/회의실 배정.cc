#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;


int main(void) {

	int n;
	cin >> n;


	vector<pair<int, int>> list;
	int start, end;
	// 회의 시작 시간과 종료시간을 입력받아 종료시간을 첫 번재 인자로 list 에 push
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		list.push_back(make_pair(end, start));
	}

	// 회의 종료시간을 기준으로 list 를 정렬
	sort(list.begin(), list.end());


	int count = 1;
	// list 의 첫 번째 인자의 종료시간을 time 으로 초기화
	int time = list[0].first;
	for (int i = 1; i < n; i++) {

		// 만약 현재 시간의 종료시간보다 다음 회의 시간의 시작 시간이 같거나 같을 경우
		// 기준 시간을 다음 회의 시간의 종료시간으로 변경후 count 를 증가
		if (time <= list[i].second) {
			time = list[i].first;
			count++;
		}
	}

	cout << count;

	return 0;
}