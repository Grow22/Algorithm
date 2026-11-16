#include <bits/stdc++.h>
#include<iostream>

using namespace std;

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
        // n과 m 은 각 배열의 길이
        int n,m;
        cin >> n >> m;


        // 길이가 n,m 인 벡터 v1,v2
        vector<int> v1(n);
        for(int i=0;i < n;i++) cin >> v1[i];
        vector<int> v2(m);
        for(int i=0;i <m;i++) cin >> v2[i];

        // 항상 벡터 v1 이 더 짧은 길이이도록 유지
        // n 은 항상 짧은 길이의 변수
        if(n >m) {
            swap(n,m);
            swap(v1,v2);
        }

        int res =INT_MIN;
        // m 의 길이가 더 길 경우


        for(int i=0;i <= m-n;i++) {
            int sum =0;
            for(int j=0;j<n; j++) {
                sum += v1[j] * v2[i+j];   
            }

            if(sum > res) res = sum;
        }
        cout << "#" << test_case << " " << res << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}