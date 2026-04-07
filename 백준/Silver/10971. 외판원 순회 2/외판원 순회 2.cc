#include <iostream>
#define MAX 11
#define INF 1e9
using namespace std;

int W[MAX][MAX];
bool visited[MAX];
int res = 1e9;
int n;

void dfs(int now, int cnt, int value, int start){
    if(cnt == n){
        if(!W[now][start]) return;
        res = min(res, value + W[now][start]);
        return;
    }
    for(int i = 1; i <= 10; i++){
        if(now == i || W[now][i] == 0 || visited[i]) continue;
        
        visited[i] = true;
        dfs(i, cnt + 1, value + W[now][i], start);
        visited[i] = false;
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> W[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        visited[i] = true;
        dfs(i, 1, 0, i);
        visited[i] = false;
    }
    
    cout << res;
    
    return 0;
}