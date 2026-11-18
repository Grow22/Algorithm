#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
    
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        // n*n 배열 선언 후 0 으로 초기화
		int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n,0));

        // 파스칼 삼각형 채우기
        for(int i=0;i<n;i++) {
         	// 맨 양옆은 0 으로 채우기
            v[i][0] = 1;
            v[i][i] = 1;
            for(int j=1;j < i;j++) {
                v[i][j] = v[i-1][j-1] + v[i-1][j]; // 왼쪽 위 + 바로 위
            }
        }
        
        // 출력
        cout << "#" << test_case << "\n";
        for(int i=0;i <n;i++) {
            for(int j=0;j <=i;j++) {
             	cout << v[i][j] << " ";
            }
           cout << "\n";
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}