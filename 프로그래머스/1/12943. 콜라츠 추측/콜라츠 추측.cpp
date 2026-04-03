#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    long long n = num;
    
    // n 이 1 이 될 때까지 반복
    while(n>1) {
        answer++;
        // 실행 횟수가 500 이상이 될 경우
        if(answer >= 500) break;
        // n 이 짝수일 경우
        if(n%2 ==0)n /=2;
        // num 이 홀수일 경우
        else n = (n *3) +1;
    }
    
    if(answer == 500) return -1;
    
    return answer;
}