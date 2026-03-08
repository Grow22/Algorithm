#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	// 기존 문자열 입력
	string base_s;
	cin >> base_s;
	int base_len = base_s.size();
	int alpha[26] = { 0, }; // 문자열의 개수를 alpha 에 저장
	// 기준 문자열의 각 알파벳 개수를 저장
	for (int i = 0; i < base_s.size(); i++) {
		alpha[base_s[i] - 'A']++;
	}

	string com_s;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {

		int same = 0;
		// 비교 문자열을 입력
		cin >> com_s;
		int comp_len = com_s.size();
		int coppy[26];
		// 기존 문자열의 알파벳 개수 배열을 coppy 에 복사
		copy(alpha, alpha + 26, coppy);

		// 비교 문자열의 각 알파벳 개수를 카운팅
		for (int j = 0; j < comp_len; j++) {
			int idx = com_s[j] - 'A';
			if (coppy[idx] > 0) {
				same++;
				coppy[idx]--;
			}
		}

		// 두 문자열의 길이가 같고 비슷한 문자열일 경우
		if (base_len == comp_len) {
			if (same == base_len || same == base_len - 1) cnt++;
		}
		// 기존 문자열(base_len)의 길이가 비교 문자열보다 1 길고 비슷한 문자열일 경우
		else if (base_len - 1 == comp_len && same == base_len - 1) cnt++;
		// 기존 문자열(base_len)의 길이가 비교 문자열보다 1 짧고 비슷한 문자열일 경우
		else if (base_len +1 == comp_len  && same == base_len) cnt++;

		else continue;
	}
	cout << cnt;
	return 0;
}