 
    #include<bits/stdc++.h>

    using namespace std;

    int main(int argc, char** argv)
    {
        
        ios::sync_with_stdio(false); cin.tie(0);
        int test_case;
        int T;
        cin>>T;

        for(test_case = 1; test_case <= T; ++test_case)
        {
            // n 은 배열의 범위, m 은 계산할 범위
            int n, m;
            cin >> n >> m;
			
            // n*n 에 원소를 입력
            int arr[15][15] = {0};
            for(int i=0;i< n;i++) 
             	for(int j=0;j < n;j++)
                    cin >> arr[i][j];
		
            int res =0;
            for(int i=0;i <= n-m;i++) {
             	for(int j=0;j <= n-m;j++) {
                 	   
                    int sum =0;
                    for(int x =0;x < m;x++) 
                        for(int y=0;y<m;y++)
                            sum += arr[i + x][j + y];
                    if(sum > res) res = sum;
                }
            }
            
            cout << "#" << test_case << " " << res << "\n";
        }
        
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
    }