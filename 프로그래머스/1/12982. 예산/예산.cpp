#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> d, int budget) {
    int answer = 0;
    
    // 최대한 많은 부서를 지원하기 위해서 작은 수부터 오름차순 정렬
    sort(d.begin(), d.end());

    for(int i=0;i < d.size();i++) {
        
        if(budget-d[i] >=0) {
            answer++;
            budget -= d[i];
        }
        else {
            break;
        }
    }
    
    return answer;
}