#include <string>
#include <vector>
#include <cctype>


using namespace std;

string solution(string s) {
    
    int index = 1;
    for(int i=0;i < s.size();i++) {
        
        if(s[i] == ' ') {
            index = 1;
            continue;
        }
        else {
            // 인덱스가 홀수일 경우 대문자로 반환
            // 인덱스가 짝수일 경우 소문자로 변환
            if(index % 2 == 0) s[i] = tolower(s[i]);
            else s[i] = toupper(s[i]);
        }
        index++;
    }
    return s;
}