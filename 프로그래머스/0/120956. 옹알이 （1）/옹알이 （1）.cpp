#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i=0;i < babbling.size();i++) {
        
        bool check = true;
        
        // 첫 번째 문자열부터 검사 시작
        for(int j=0;j < babbling[i].size();j++){
            
            if(babbling[i].substr(j,3) == "aya") j+=2;
            else if(babbling[i].substr(j,2) == "ye") j+=1;
            else if(babbling[i].substr(j,3) == "woo") j+=2;
            else if(babbling[i].substr(j,2) == "ma") j +=1;
            else { // 발음하지 못하는 발음이 나타났을 경우
                check = false;
                break;
            }    
        }
        if(check) answer++;
    }
    return answer;
}