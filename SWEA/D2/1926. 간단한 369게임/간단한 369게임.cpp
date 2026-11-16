#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
	
    int n;
    cin >> n;
    
    for(int i=1;i <=n;i++) {
		int x = i;
        int cnt =0;
        // 각 자리수를 검사
        while(x > 0) {
            
            int d = x % 10;
            if(d ==3 || d == 6 || d == 9) cnt++;
            x /= 10;
        }
        // 만약 3,6,9 가 하나라도 존재할 경우
        if(cnt >0) 
        {
          for(int i=0;i < cnt;i++) cout << "-";
          cout << " ";
        }
        // 일반 숫자일 경우
        else cout << i << " ";
    }
	return 0;
}