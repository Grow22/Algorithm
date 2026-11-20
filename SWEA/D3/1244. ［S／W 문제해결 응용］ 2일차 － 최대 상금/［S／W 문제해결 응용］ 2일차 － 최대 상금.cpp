#include<bits/stdc++.h>

using namespace std;

set<string> visited[10];
int k,res; // k 는 교환 횟수, res 는 출력할 결과

// cnt 는 교환한 횟수
void dfs(string& s, int cnt) {
    
    // 만약에 교환 횟수를 다 채웠을 경우
    if(cnt == k) {
     	res = max(res,stoi(s));
        return;
    }
    
    // 같은 횟수에서 동일한 문자열이 나왔을 경우
    if(visited[cnt].count(s)) return;
    visited[cnt].insert(s); // 나오지 않았을 경우 문자열 s 를 추가
    
    int n = s.length();
    // 두 개의 쌍을 교환하면서 비교
    for(int i=0;i<n;i++) {
     	for(int j=i+1;j<n;j++)   {
         	swap(s[i],s[j]);
            dfs(s,cnt+1);
            swap(s[i],s[j]); // 원래대로 복구
        }
    }
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
		string s;
        cin >> s >> k;
		
        // set 초기화
        for(int i=0;i<10;i++) visited[i].clear();
        
        res = 0;
        
        dfs(s,0);
        
        cout << "#" << test_case << " " << res << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}