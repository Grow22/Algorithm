#include<bits/stdc++.h>

using namespace std;

int n,m;
// 경로를 저장할 벡터 v
vector<vector<int>> v(11, vector<int>(11));
vector<bool> visited(11);
int res;

void dfs(int cur, int len) {
 
    res = max(res,len);
   
   for(int i=1;i<=n;i++){
       // 만약 v -> i 의 경로가 존재하고 아직 방문하지 않았을 경우
       if(!visited[i] && v[cur][i]) {
        	visited[i] = true;
           dfs(i,len+1);
           visited[i] = false;
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
        // n 은 정수의 범위, m 은 간선의 개수
		cin >> n >> m;
		
        res = 0;
        
        // 그래프 초기화
        for(int i=0;i<=10;i++)
            for(int j=0;j<=10;j++) v[i][j] =0;
        
        // 원소 입력
        for(int i=0;i <m;i++) {
         	int x,y;
            cin >> x>> y;
            v[x][y] = v[y][x] = 1;
        }
        // dfs 탐색 시작
        for(int i=1;i <=n;i++) {
         	visited[i] = true;
            dfs(i,1);
            visited[i]= false;
        }
        
        cout << "#" << test_case << " " << res << "\n";
       
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}