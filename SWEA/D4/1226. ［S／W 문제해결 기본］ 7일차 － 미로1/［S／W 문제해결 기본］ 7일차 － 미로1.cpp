#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v(16, vector<int>(16));
bool visited[16][16] = { false };


// 오른쪽,아래,왼쪽,위
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

// 결과를 나타낼 변수
int res;

void find(int x, int y) {

    // 위치를 저장할 큐
    queue<pair<int, int>> q;

    q.push({ x,y });

    // 큐가 비지 않을 동안 반복
    while (!q.empty()) {

        // 원소 꺼내기
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        // 만약 도착했을 경우
        if (v[cx][cy] == 3) {
            res = 1;
            return;
        }

        // 4개 방향으로 이동 가능하면 원소 넣기
        for (int i = 0; i < 4; i++) {

            int mx = cx + dx[i];
            int my = cy + dy[i];
            // 만약 벽이 아니고 이동 가능할 경우
            if (v[mx][my] !=1&& !visited[mx][my]) {
                visited[mx][my] = true;
                q.push({ mx,my });

            }
        }
    }

}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
    int test_case;
    int T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;


        res = 0;
        for (int i = 0; i <16; i++) {
            for (int j = 0; j < 16; j++) {
                visited[i][j] = false;
            }
        }

        // sx, sy 는 시작정점
        int sx, sy;
        // 미로 입력
        for (int i = 0; i < 16; i++) {

            string s;
            cin >> s;
            for (int j = 0; j < 16; j++) {

                v[i][j] = s[j] - '0';
                if (v[i][j] == 2) {
                    sx = i;
                    sy = j;
                }
            }


        }
        visited[sx][sy] = true;
        find(sx, sy);

        cout << "#" << test_case << " " << res << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
