#include <iostream>
using namespace std;
string word, ring;
int N, answer;

int res;
// word 단어가 포함되어 있는 지를 검사
int find(int i) {

    for (int j = 0; j < word.size(); j++) {
        if (word[j] != ring[j + i]) {
            return 0;
            break;
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> word >> N;
   

    for (int i = 0; i < N; i++) {

        cin >> ring;

        // 원의 마지막에 단어 추가
        for (int i = 0; i < word.size() - 1; i++) {
            ring.push_back(ring[i]);
        }

        for (int i = 0; i <= ring.size() - word.size(); i++) {

            if (find(i)) {
                res++;
                break;
            }
        }
    }

    cout << res;


    return 0;
}