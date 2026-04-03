#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    
    string answer = "";
    int size = phone_number.size(); // 전화번호의 길이를 저장
    
    for(int i=0;i < size-4;i++) {
        answer.push_back('*');
    }
    
    for(int i=size-4;i < size;i++) {
        answer.push_back(phone_number[i]);
    }
    
    return answer;
}