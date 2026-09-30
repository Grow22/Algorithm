#include <vector>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    int max = 3000;

    vector<int> v(max + 1, 0);

    for (int i = 2; i * i <= max; i++) {
        // i가 소수 후보일 경우
        if (v[i] == 0) {
            for (int j = i * i; j <= max; j += i) {
                v[j] = 1;
            }
        }
    }

    // 세 수를 골라 합이 소수인지 확인
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = nums[i] + nums[j] + nums[k];

                // 소수일 경우 개수 증가
                if (v[sum] == 0) answer++;
            }
        }
    }

    return answer;
}