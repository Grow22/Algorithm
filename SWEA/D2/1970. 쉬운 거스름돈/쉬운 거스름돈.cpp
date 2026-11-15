#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

    int arr[8] = {50000,10000,5000,1000,500,100,50,10};
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin >> n;
        	
        int res[8];
        for(int i=0;i < 8;i++) {
         	
            int x = n / arr[i];
    		res[i] = x;
            n -= arr[i] * x;
        }

        // 결과 출력
        cout << "#" << test_case << "\n";
        for(int i=0;i < 8;i++) {
            cout << res[i] << " ";
	}
        cout << "\n";
    }
	return 0;
}