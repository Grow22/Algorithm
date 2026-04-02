#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for(int i=0;i < arr.size();i++) {
        if(arr[i] % divisor == 0) answer.push_back(arr[i]);
    }
    
    
    // divisor 로 나누어지는 값이 없을 경우
    if(answer.size() == 0) {
        answer.push_back(-1);
    }
    
    // 결과 정렬 후 반환
    sort(answer.begin(), answer.end());
    return answer;
}