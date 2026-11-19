#include<bits/stdc++.h>

using namespace std;

// n 은 음식 개수, l 은 칼로리
int n,l,res;

int taste[20], cal[20]; // taste 는 맛, cal 는 칼로리

// tSum 은 맛 합, cSum 은 칼로리 합
void dfs(int idx, int tSum, int cSum) {
    
    // 칼로리를 초과할 경우
    if(cSum > l) return;
    
    // 모든 재료를 둘러보았을 경우
    if(idx == n) {
     	   res = max(res, tSum);
        	return;
    }
    
    // 현재 맛을 포함
    dfs(idx+1,tSum + taste[idx], cSum + cal[idx]);
    // 현재 맛을 포함 x
    dfs(idx+1,tSum,cSum);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >>l;
        for(int i=0;i < n;i++) cin >> taste[i] >> cal[i];
        
        res = 0;
        dfs(0,0,0);
		
        cout << "#" << test_case << " " << res << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}