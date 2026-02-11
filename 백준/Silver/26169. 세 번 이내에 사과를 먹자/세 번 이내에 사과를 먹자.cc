#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<int>> v;
vector<vector<int>> ans;
bool visit[100][100];
int r, c, cnt = 0;

void dfs(int y, int x, int num, int apple)
{
    visit[y][x] = true;
    if (num > 3)
    {
        return;
    }
    if (apple >= 2)
    {
        //cout << y << " " << x << "\n";
        //cout << apple << "    ";
        cnt = 1;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 5 || ny < 0 || nx >= 5 || nx < 0)
        {
            continue;
        }
        if (visit[ny][nx])
        {
            continue;
        }
        if (ans[ny][nx] == -1)
        {
            continue;
        }
        if (ans[ny][nx] == 1)
        {
            dfs(ny, nx, num + 1, apple + 1);
            visit[ny][nx] = false;
        }
        else
        {
            dfs(ny, nx, num + 1, apple);
            visit[ny][nx] = false;
        }


    }

}


int main()
{
    int a = 0;
    v.resize(5, vector<int>(5));
    ans.resize(5, vector<int>(5));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> ans[i][j];
            v[i][j] = 0;
        }
    }

    cin >> r >> c;
    if (ans[r][c] == 1)
    {
        a += 1;
    }
    dfs(r, c, 0, a);
    cout << cnt;
    return 0;
}