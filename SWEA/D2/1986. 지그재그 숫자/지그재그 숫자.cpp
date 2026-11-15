#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
    
	int test_case;
	int T; // 테스트 케이스 개수

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin >> n; // n은 입력받을 변수
        
        int sum =0;
        for(int i=1;i <=n;i++) {
            
            // 홀수면 더하기
            if(i % 2 ==1) sum += i;
            // 짝수면 빼기
            else sum -= i;
        }	
        cout << "#" << test_case << " " << sum << "\n";
	}
	return 0; 
}