#include <string>
#include <vector>

using namespace std;

// number 는 학생들이 지니고 있는 점수
int solution(vector<int> number) {
    int answer = 0;
    
    for(int i=0;i<  number.size()-2;i++) {
        int sum =0;
        
        sum += number[i];
        int tmp = sum;
        for(int j=i+1;j < number.size()-1;j++) {
            sum = tmp; // i 까지 더한 값으로 다시 초기화
            sum += number[j];
            for(int k=j+1;k < number.size();k++) {
               
                // 세 명의 점수희 합이 0 인 경우
                if((sum + number[k]) == 0) answer++;
            }
        }
    }
    
    return answer;
}