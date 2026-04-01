#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;


long long solution(long long n) {
    long long answer = 0;
    
    // 1. n 의 각 자릿수를 기준으로 저장
    int x;
    vector<int> v;
    while(n > 0) {
        
        x = n % 10;
        n /= 10;
        
        v.push_back(x);
    }
    // 저장한 각 자릿수를 정렬
    sort(v.begin(),v.end());
    
    
    // 112378
    for(int i=v.size()-1;i >= 0;i--) {
        answer += v[i] * pow(10,i);
    }
    
    
    return answer;
}