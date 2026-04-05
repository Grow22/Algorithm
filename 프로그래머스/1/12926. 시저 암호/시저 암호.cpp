#include <string>
#include <vector>

using namespace std;

// s 는 입력받을 문자열
// n 은 밀 크기
string solution(string s, int n) {
    string answer = "";
    
    for(int i=0;i < s.size();i++) {
        // 공백일 경우
        if(s[i] == ' ') answer += ' ';   
        else {
            // 소문자일 경우
            if('a' <= s[i] && s[i] <= 'z') {
            
                int temp =  s[i] +n;
                // 문자가 범위를 벗어날 경우
                if(temp > 'z') temp = temp -26;
                answer += (char)temp;
            } 
            // 대문자일 경우
            else if('A' <= s[i] && s[i] <= 'Z') {
                int temp = s[i] + n;
                if(temp > 'Z') temp = temp - 26;
                answer += (char)temp;
            }
        }
    }
    
    return answer;
}