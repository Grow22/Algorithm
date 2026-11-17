#include<bits/stdc++.h>

#include<iostream>

using namespace std;

int n,k,cnt;
int A[20]; // 원소를 입력받을 배열 A

void dfs(int idx, int sum) {
    
    // 모든 배열의 원소를 둘러봤을 경우
    if(idx == n) {
    	// 합이 k 와 같을 경우
        if(sum == k) cnt++;
        return;
    }
    
    // 현재 인덱스의 숫자를 넣는 경우
    dfs(idx+1, sum + A[idx]);
    // 현재 인덱스의 숫자를 넣지 않는 경우
    dfs(idx+1, sum);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // n 개의 원소를 입력
		cin >> n>> k;
        for(int i=0;i <n;i++) cin >> A[i];
		
        // cnt 값 0으로 초기화
        cnt =0;
		dfs(0,0); // 처음 값부터 부분 수열 구하기 
        
        cout << "#" << test_case << " " << cnt << "\n";
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}