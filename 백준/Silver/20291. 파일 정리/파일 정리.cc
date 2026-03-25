#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;


// [문자열, 문자열의 개수] 를 나타낼 map m
map<string, int> m;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// n 은 파일의 개수
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;

		// . 이 있는 곳의 위치를 반환
		int index = s.find('.');

		// . 다음(index+1) 부터 마지막 문자열까지의 문자열을 반환
		string tmp = s.substr(index + 1, s.size());

		// 문자열에 해당하는 정수 값을 증가
		m[tmp]++;
	}

	// m 의 처음 인덱스를 나타낼 변수 res
	// map 은 선언하지 않을 시 ordered_map 으로 선언되기 때문에 문자열 순으로 출력
	for (auto res : m) {
		cout << res.first << ' ' << res.second << '\n';
	}

	return 0;
}