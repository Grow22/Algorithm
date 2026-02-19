#include <iostream>
#include <vector>

using namespace std;

int n, k;

vector<int> res;

int cnt; // 만들어진 순열의 차례를 표현

void solve(int sum) {

    // n 을 초과했을 경우
    if (sum > n) {
        return;
    }

    // 구하는 값 n 에 도달하였을 경우
    if (sum == n) {
        cnt++;
        // k 번째 값에 도달하였을 경우 결과 출력
        if (cnt == k) {

            for (int i = 0; i < res.size(); i++) {
                cout << res[i];
                if (i != res.size() - 1) {
                    cout << '+';
                }
            }
        }
        return;
    }
    
    for (int i = 1; i <= 3; i++) {
        res.push_back(i);
        solve(sum + i);
        res.pop_back();
    }
}

int main()
{
    cin >> n >> k;

    solve(0);

    if (cnt < k) {
        cout << -1;
    }

    return 0;
}