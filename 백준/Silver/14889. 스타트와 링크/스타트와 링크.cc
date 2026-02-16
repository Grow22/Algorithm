#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
int N;
int arr[21][21];	
int visit[21];

int res=999999;

void solve(int idx, int cnt) {

	vector<int> start;
	vector<int> link;
	int start_score=0;
	int link_score=0;

	// 모든 팀 수만큼 뽑았을 경우
	if(cnt == N / 2) {


		for (int i = 0; i < N; i++) {
			// start 팀에 해당하는 경우
			if (visit[i]) {
				start.push_back(i);
			}
			else {
				link.push_back(i);
			}
		}
		// start, link 의 총 점수를 계산
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {

				start_score += arr[start[i]][start[j]];
				link_score += arr[link[i]][link[j]];
			}
		}
		if (abs(start_score - link_score) < res) {
			res = abs(start_score - link_score);
		}
	}

	// 팀을 구성하는 경우
	else {

		for (int i = idx; i < N; i++) {

			if (visit[i]) {
				continue;
			}
			else {
				visit[i] = true;
				solve(i + 1, cnt + 1);
				visit[i] = false;
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0);

	cout << res;
	return 0;
}