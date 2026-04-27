#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0); // 결과를 담을 배열 (크기 n, 초기값 0)

    // 질문자님의 4번 문제 논리 그대로 적용!
    for (int i = 0; i < n; i++) {
        // i번째 시점의 주식을 기준으로, 그 이후(i+1)의 미래를 탐색합니다.
        for (int j = i + 1; j < n; j++) {
            answer[i]++; // 일단 다음 초를 확인했으니 1초 증가 (카운트)
            
            // 만약 미래의 가격(prices[j])이 현재 가격(prices[i])보다 떨어졌다면?
            if (prices[i] > prices[j]) {
                break; // 질문자님의 핵심 로직! 시야가 막혔으니 더 이상 미래를 보지 않고 중단.
            }
        }
    }
    
    return answer;
}