#include<bits/stdc++.h>

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
    int test_case;
    int T;

    cin>>T;

    // 오른쪽,아래,왼쪽,위
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;

        vector<vector<int>> v(n, vector<int>(n));

        int x=0, y=0, dir=0;
        for(int num =1;num <= n*n;num++) {

            // x,y 원소에 값 삽입
            v[x][y] = num;

            // 다음 칸 계산
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 만약 범위를 벗어났거나 이미 채웠을 경우
            if(nx < 0 || nx >=n || ny <0 || ny >=n || v[nx][ny] != 0) {
                // 방향 전환후 다시 계산
                dir = (dir +1) %4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            x = nx;
            y = ny;
        }

        cout << "#" << test_case << "\n";
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << v[i][j] << " ";   
            }
            cout << "\n";
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}