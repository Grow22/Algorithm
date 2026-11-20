#include<bits/stdc++.h>

using namespace std;

// n 은 과자의 개수, m 은 최대 무게
int n,m;
// 과자의 무게를 나타낼 배열 v
vector<int> v(1000);

int res;

void dfs(int idx, int cnt, int sum) {
    
   // 무게를 초과했을 경우
   if(sum >m) return;;
   // 다 골랐을 경우
   if(cnt == 2) {
       res = max(res,sum);
       return;
   }
    // 만약 끝까지 다 살펴봤고 2개를 고르지 않았을 경우 return
    if(idx == n) return;
    
    dfs(idx+1,cnt+1,sum +v[idx]); // 현재 과자를 골랐을 경우
    dfs(idx+1,cnt,sum); // 현재 과자를 고르지 않았을 경우
   
}

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
        cin >> n >> m;
		
        // 과자의 무게를 입력
        for(int i=0;i <n;i++) cin >> v[i];
		
        res = 0; // 결과 0 으로 초기화
        
        dfs(0,0,0);
        
        // 다 살펴봣는데 과자를 들고갈 방법이 없을 경우
        if(res ==0) res = -1;
        
        cout << "#" << test_case << " " << res << "\n";
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}