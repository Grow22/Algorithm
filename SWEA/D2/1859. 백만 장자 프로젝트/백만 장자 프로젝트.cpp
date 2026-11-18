#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        
    	int mx =0;
        long long res=0;
        for(int i=n-1;i >=0;i--) {
         	if(v[i] >mx) mx = v[i]; // 현재 값이 최대값이면 값을 갱신
            else res += mx - v[i]; // 현재 값이 최대값이 아니면 최대값을 기준으로 갱신
        }
		cout << "#" << test_case << " " << res << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}