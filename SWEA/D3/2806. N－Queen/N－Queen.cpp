    #include<bits/stdc++.h>

    using namespace std;

    int pos[15]; // 각 행의 열이 있는 행을 기록
    int n,cnt;

    // r 행에 놓인 퀸이 이전 행과 겹치는 지를 검사
    bool check(int r){

        for(int i=0;i<r;i++) {

            // 같은 행에 놓였을 경우
            if(pos[i] == pos[r]) return false;
            if(abs(pos[r] - pos[i]) == r-i) return false; // 대각선에 놓였을 경우 
        }
        return true;
    }

    void dfs(int r) {
        // 모든 행에 놓았을 경우
        if(n ==r) {
            cnt++;
            return;
        }
        // 모든 행의 모든 열에 대하여 조사
        for(int c=0;c<n;c++) {
             pos[r] = c;
             if(check(r)) dfs(r+1); // 안전할 경우 다음 행으로 넘어감
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
            cin >>n;		
            cnt =0;
            dfs(0);

            cout << "#" << test_case << " " << cnt << "\n";
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
    }