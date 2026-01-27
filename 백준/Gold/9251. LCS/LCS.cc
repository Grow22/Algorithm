#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dp[1001][1001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 최장 공통 부분을 비교할 수열 s1, s2
    string s1, s2;
    cin >> s1 >> s2;

    // 문자열 비교를 위해 각 사이즈 별로 반복물은 실행
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {

            // (1) s1의 i 번째 문자와 s2 의 j 번째 문자가 같은 경우
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // (2) 문자가 같이 않은 경우
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[s1.size()][s2.size()];

    return 0;
}
