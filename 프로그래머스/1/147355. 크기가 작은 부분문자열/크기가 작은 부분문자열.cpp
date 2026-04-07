#include <string>
#include <vector>


using namespace std;

// p 는 작아야 할 문자열
int solution(string t, string p) {
    int answer = 0;
    
    for(int i=0;i <= t.size() - p.size();i++)
    {
        string tmp = t.substr(i, p.size());
        if(p >= tmp) answer++;
    }
    
    return answer;
}