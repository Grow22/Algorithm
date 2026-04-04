#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    sort(s.rbegin(), s.rend());
    
    answer += s;
    
    
    return answer;
}