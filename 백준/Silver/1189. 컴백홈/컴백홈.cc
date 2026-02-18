#include <iostream>

using namespace std;


int r, c, k;

char arr[6][6];
int visit[6][6];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };



int res;

void solve(int x, int y, int dist) {


    // 도착 지점에 도착하였을 경우
    if (x == 1 && y == c) {
        if (dist == k) res++;
        return;
    }

    visit[x][y] = 1;

    // 네 방향으로 탐색을 진행하며
    for (int i = 0; i < 4; i++) {
        
        int X = x + dx[i];
        int Y = y + dy[i];


        // 범위를 벗어난 경우
        if (X > r || X < 1) continue;
        if (Y > c || Y < 1) continue;
        

        // 가로막힌 길이거나 이미 방문한 길인 경우
        if (arr[X][Y] == 'T'|| visit[X][Y] == 1) continue;

        solve(X, Y, dist+1);
    }

    visit[x][y] = 0;
}

int main()
{

    cin >> r >> c >> k;
    

    char x = ' ';
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> x;
            arr[i][j] = x;
        }
    }
        
    solve(r, 1,1);

    cout << res;
 
    return 0;
}