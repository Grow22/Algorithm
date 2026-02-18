#include <iostream>

using namespace std;

int k;
char signs[10];
int pick[10];
bool is_used[10];
string max_ans = "0000000000", min_ans = "9999999999";

string makeString(){

    string res = "";

    for (int i = 0; i <= k; i++) {
        res += pick[i] + '0';
    }

    return res;
}

void backtrack(int idx) {
    
    // 정수를 모두 뽑았을 경우
    // 결과 업데이트
    if (idx > k) {
        string res = makeString();
        max_ans = max(max_ans, res);
        min_ans = min(min_ans, res);
    }

    else {
        for (int i = 0; i < 10; i++) {
            if (is_used[i]) continue;
            if (idx > 0) {
                if(signs[idx - 1] == '<' && pick[idx - 1] > i) continue;
                if(signs[idx - 1] == '>' && pick[idx - 1] < i) continue;
            }

            // 부등호 관계가 성립할 경우
            is_used[i] = true;
            pick[idx] = i;
            backtrack(idx+1);
            is_used[i] = false;
        }
    }
}

int main()
{
 
    // k 개의 부등호를 입력
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> signs[i];
    }

    backtrack(0);

    cout << max_ans << '\n';
    cout << min_ans;
    return 0;
}