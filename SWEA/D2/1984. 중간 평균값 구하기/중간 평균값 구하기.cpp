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
        // 원소 10개를 입력
		int arr[10];
        for(int i=0;i <10;i++) cin >> arr[i];
		
        // 원소 10 개를 정렬
        sort(arr,arr+10);
        
        int sum =0;
        
        // 최소/최대 수를 제외한 합을 더함
        for(int i=1;i <9;i++) sum += arr[i];
        
        int res = (round)(sum / 8.0);
        
        // 출력
        cout << "#" << test_case << " " << res << "\n"; 
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}