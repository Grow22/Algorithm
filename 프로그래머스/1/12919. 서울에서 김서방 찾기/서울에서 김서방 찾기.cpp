#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    
    for(int i=0;i < seoul.size();i++) {
        // 김서방을 발견했을 경우
        if(seoul[i] == "Kim")
        {
            answer ="김서방은 " + to_string(i) + "에 있다";
        }
    }
    return answer;
}