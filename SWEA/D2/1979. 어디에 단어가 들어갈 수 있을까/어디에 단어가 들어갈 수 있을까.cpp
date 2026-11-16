#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        // n 은 2차원 배열의 크기, k 는 단어가 들어갈 크기
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(n));

        // 원소 입력
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];

        int res = 0;

        // 가로 검사
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 0) {      // 0이면 구간 끝
                    if (cnt == k) res++;
                    cnt = 0;
                }
                else {                   // 1이면 연속 개수 증가
                    cnt++;
                }
            }
            if (cnt == k) res++;         // 줄 끝 확인
        }

        // 세로 검사
        for(int i=0;i<n;i++) {
         	int cnt =0;
            for(int j=0;j <n;j++) {
             	if(v[j][i] ==0) {
                 	if(cnt ==k) res++;
                    cnt =0;
                }
                else cnt++;
            }
            if(cnt ==k) res++;
        }


        cout << "#" << test_case << " " << res << "\n";
    }

    return 0;
}