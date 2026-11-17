#include<bits/stdc++.h>

#include<iostream>

using namespace std;

int k,res;
set<string> visited[11];

void dfs(string& s, int cnt) {
 
    // k 번째 교환을 마친 경우 결과값 비교 후 연산
    if(cnt == k)	{
    	res = max(res, stoi(s));    
        return;
    }
    // 같은 횟수에서 같은 숫자인 경우 중단
    if(visited[cnt].count(s)) return;
    visited[cnt].insert(s); // 나오지 않은 숫자일 경우 +1
    
    // 모든 두 자리 수 쌍 계산
    int n = s.size();
    for(int i=0;i <n;i++) {
     	for(int j=i+1;j<n;j++) {
         	swap(s[i],s[j]);
            dfs(s, cnt+1);
            swap(s[i],s[j]);
        }
    }
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        // s 는 문자열, k 는 바꿀 횟수
		string s;
        cin >> s >> k;
		
		res = 0;
        // 테스트케이스마다 초기화
        for(int i=0;i <=10;i++) visited[i].clear();
		
        dfs(s,0);
        
        cout << "#" << test_case << " " << res << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}