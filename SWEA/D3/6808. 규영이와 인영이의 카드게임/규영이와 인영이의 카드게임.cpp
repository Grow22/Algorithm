#include<bits/stdc++.h>

using namespace std;

int gy[9], in[9]; // 규영/인영이의 점수
bool visited[9]; // 인영이의 카드 사용 여부
int win, lose;

// gs 는 규영의 점수의 합, is 는 인영의 점수의 합
void dfs(int round, int gs, int is) {
    
    // 라운드가 9 번 돌았을 경우
    if(round ==9) {
     	if(gs > is) win++;   // 규영이 이길 경우
        else lose++;
        return;
    }
    
    for(int i=0;i <9;i++) {
     	if(visited[i]) continue; // 이미 낸 카드일 경우
        visited[i] = true;
        
        int sum = gy[round] + in[i];
        if(gy[round] > in[i]) dfs(round+1, gs + sum, is);
        else dfs(round+1,gs, is + sum);
        
        visited[i] = false;
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
		
        // 규영이의 카드를 입력
        bool has[19] = {false};
        for(int i=0;i<9;i++) {
         	cin >> gy[i];
            has[gy[i]] = true;
        }
		
        // 인영이의 카드를 입력
        int idx = 0;
        for(int i=1;i<=18;i++) {
         	if(!has[i]) in[idx++] = i;   
        }
		
        win = lose = 0;
        dfs(0,0,0);
        
        cout << "#" << test_case << " " << win << " " << lose << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}