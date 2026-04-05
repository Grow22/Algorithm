#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.size());
    
    int dis=0; // 거리를 나타낼 변수
    for(int i = s.size()-1;i > 0;i--) {
        char c = s[i];
        bool find = false;
        for(int j= i-1;j >=0;j--) {
            if(c == s[j]) {
                dis = i -j;
                find = true;
                break;
            }
        }
        
        // 같은 원소를 발견했을 경우 두 원소 간의 거리로 갱신
        // 발견하지 못했을 경우 -1 로 갱신
        if(find) answer[i] = dis;
        else answer[i] = -1;
    }
    // 처음 원소 갱신
    answer[0] = -1;
    return answer;
}