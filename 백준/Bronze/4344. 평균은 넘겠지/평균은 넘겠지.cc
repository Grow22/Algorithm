#include <iostream>

#include <vector>
using namespace std;

int main() {
	
	int C; // 테스트 케이스 개수 C
	cin >> C;
	int n; // 학생의 수 n
	int s; // 학생 s
	for (int i = 0; i < C; i++) {

		cin >> n; // 학생의 수를 n 에 입력

		vector<int> student;
		double avg = 0; // 학생들의 점수의 평균을 avg 에 저장
		double cnt = 0;// 평균을 넘는 학생들의 수를 cnt 에 저장
		for (int j = 0; j < n; j++) {
			cin >> s;
			student.push_back(s);
		}
		
		// vector 에 저장된 학생들의 점수의 평균을 구함
		for (int i = 0; i < n; i++) {
			avg += student[i];
		}
		avg = avg / n;

		// 평균을 넘는 학생들의 수 구하기
		for (auto& val : student) {
			if (val > avg) {
				cnt++;
			}
		}
		double result= (cnt / n) * 100;

		printf("%.3lf%%\n", result);
	}
}