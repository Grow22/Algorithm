#include <string>
#include <vector>
#include <iostream>

using namespace std;

// food 는 음식
/*

첫 번째 원소는 항상 물 --> 1

*/
string solution(vector<int> food) {
    string answer = "";
    
    for(int i=1;i < food.size();i++) {
        if(food[i] == 1) continue;
        int food_size = (food[i]  / 2);
        
        //cout << food_size;
        for(int j=0;j < food_size;j++) {
            answer += to_string(i);
        }
    }
    
    answer += '0';
    
    for(int i=food.size()-1;i > 0;i--) {
        if(food[i] == 1) continue;
        int food_size = (food[i] / 2);
        
        for(int j=0;j < food_size;j++) {
            answer += to_string(i);
        }
    }
    
    return answer;
}