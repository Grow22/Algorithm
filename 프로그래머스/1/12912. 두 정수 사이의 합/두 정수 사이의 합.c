#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a, b 사이의 정수의 합을 출력
long long solution(int a, int b) {
    long long answer = 0;
    
    // a < b 인 경우
    if(a<b) {
         for(int i=a;i <= b;i++) 
            answer += i;
    }
    // a < b 인 경우
    else if(a>b) {
        for(int i=b;i <= a;i++) 
            answer += i;
    }
    // a == b 인 경우
    else {
        return a;
    }
    return answer;
}