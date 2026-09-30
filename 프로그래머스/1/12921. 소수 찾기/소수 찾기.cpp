#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0;
    
    vector<int> v(n+1,0);
    
    
    for(int i=2;i*i <=n;i++) {
        
        // number i 값이 0 인 경우 소수 후보(1인 경우 소수가 xx)
        if(v[i] ==0) {
            // 소수가 아닌 수들을 지워 나감
            for(int j=i*i;j <=n;j += i) {
                v[j] =1;
            }
        }
    }
    
    for(int i=2;i <=n;i++){
        if(v[i] ==0) answer++;
    }   
    return answer;
}