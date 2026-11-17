#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
	int test_case;
    int T =10;

    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 건물 개수를 입력
		int n;
        cin >> n;

        // 건물 높이를 입력
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
		
        // 결과 변수 res 선언
        int res =0;
       
        for(int i=2;i< n-2;i++) {
            // 양 옆 2 건물 중 최대 높이를 구함
            int m = max({v[i-2],v[i-1],v[i+1],v[i+2]});
            // 좌우 양 옆의 건물들의 최대 높이보다 높이가 클 경우 
            if(v[i] > m) res += v[i] - m;
        }
        
        cout << "#" << test_case << " " <<  res << "\n";
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}