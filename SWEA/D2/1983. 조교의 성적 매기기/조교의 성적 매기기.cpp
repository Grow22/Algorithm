#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
    int test_case;
    int T;

    cin>>T;
    string grade[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
    for(test_case = 1; test_case <= T; ++test_case)
    {
        // n 은 학생수, k 는 알고 싶은 학생 k
        int n,k;
        cin >> n;
        cin >> k;

        // n 명의 학생의 3개의 점수를 저장할 벡터 v
        vector<vector<int>> v(n, vector<int>(3));

        for(int i=0;i < n;i++) 
            for(int j=0;j<3;j++) cin >> v[i][j];

        vector<double> score(n,0);

        for(int i=0;i<n;i++) {
            score[i] = v[i][0] * 0.35 + v[i][1] * 0.45 + v[i][2] * 0.20;
        }
        
        double target = score[k-1]; // k 번째 학생의 점수를 target 에 저장
        
        int rank =0;
        for(int i=0;i<n;i++) {
         	if(score[i] > target) rank++; 
        }
        
        int res = rank /(n/10);
        
        cout << "#" << test_case << " " << grade[res] << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}