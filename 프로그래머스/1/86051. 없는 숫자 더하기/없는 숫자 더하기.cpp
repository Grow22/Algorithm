#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// numbers 에는 0~9 까지의 숫자가 들어 있음 까지의 숫자가 들어 있음
int solution(vector<int> numbers) {
    int answer = 0;
    
    // 먼저 numbers 를 정렬
    sort(numbers.begin(), numbers.end());
    
    vector<int> v(10,0); // 값이 존재하는 지를 판별하는 배열 arr
    for(int i=0;i < numbers.size();i++) {
        int index = numbers[i];
        v[index] = 1;
    }
    
    // 존재하지 않는 값을 answer 에 반영
    for(int i=0;i < 10;i++) {
        
        if(!v[i])  answer+= i;
        
    }
    
    
    return answer;
}