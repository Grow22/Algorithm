#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int zero=0;
int one=0;

// 피보나치 값들을 fib 배열에 저장
int fibZero[100] = {1,0,0};
int fibOne[100] =  {0,1,1};
void fibonacci(int n) {


    // ex) n = 4
    for (int i = 2; i <= n; i++) {
        
        fibZero[i] = fibZero[i - 1] + fibZero[i-2];
        fibOne[i] = fibOne[i - 1] + fibOne[i - 2];
       
    }
    
    // 문제에서 제시한 코드로 작성 시 시간초과 발생
    /* 
    if (n == 0) {
        zero++;
        return 0;
    }
    else if (n == 1) {
        one++;
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
    */
}
int main(void) {

    int N;

    cin >> N;

    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        fibonacci(x);

        if (i == N - 1) {
            cout << fibZero[x] << ' ' << fibOne[x];
        }
        else cout << fibZero[x] << ' ' << fibOne[x] << '\n';
    }
    
    return 0;
}