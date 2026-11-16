#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    
    ios::sync_with_stdio(false); cin.tie(0);	 
	int test_case;
	int T;
    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

		int num;
        cin >> num;
        
        int arr[101] ={0};
        for(int i=0;i < 1000;i++) {
            // 입력 받은 점수를 증가
         	int score;
            cin >> score;
            arr[score]++;
        }
		
        int res = 0; // 결과 인덱스(점수)
        // 최빈 점수를 출력
        for(int i=1;i < 101;i++) {
         	   if(arr[i] >= arr[res]) res = i;
        }
		cout << "#" << test_case << " " << res << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}