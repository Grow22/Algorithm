#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    int size = arr.size();
    vector<int> answer;
    // arr 에 원소가 존재하지 않을 경우
    if(arr.size() == 0) return answer;
    
    answer.push_back(arr[0]);
    for(int i=1;i < size;i++) {
        if(answer.back() == arr[i]) continue; // 만약 원소가 삽입된 answer 의 마지막 원소와 현재 원소가 같을 경우
        else answer.push_back(arr[i]);
    }
    
    return answer;
}