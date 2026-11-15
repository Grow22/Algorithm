#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string s;
        cin >> s;
        
        int res = 1;
        int last_index = s.length()-1;
        for(int i=0;i < s.length()/2;i++) {
         	   
            if(s[i] != s[last_index - i]) 
            {
                res = 0;
                break;
            }
        }
        
        cout << "#" << test_case << " " << res << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}