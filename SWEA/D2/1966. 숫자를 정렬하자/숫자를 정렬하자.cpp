#include<iostream>
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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i < n;i++) {
         	cin >> v[i];   
        }
		
        // 원소 정렬
        sort(v.begin(), v.end());
        
        cout << "#" << test_case << " ";
        for(int i=0;i < n;i++) {
         	cout << v[i] << " ";  
        }
        cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}