#include <string>
#include <iostream>
using namespace std;

// 문자열 s 는 p,y 가 섞여 있음
bool solution(string s)
{
    bool answer = true;

    int cntP = 0; // 문자 p 의 개수를 나타낼 변수 cntP
    int cntY = 0; // 문자 y 의 개수를 나타낼 변수 cntP
    for(int i=0;i < s.size();i++) {
        if(s[i] == 'p' || s[i] == 'P') cntP++;
        else if(s[i] == 'y' || s[i] == 'Y') cntY++;
    }

    if(cntP != cntY) answer = false;
    return answer;
}