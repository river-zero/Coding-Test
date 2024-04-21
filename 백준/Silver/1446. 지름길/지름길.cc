#include <iostream>
#include <algorithm>

using namespace std;

struct Road {
    int start, end, length;
};

bool cmp(const Road &r1, const Road &r2) {
    return r1.end < r2.end;
}

int main() {
    int N, D;
    cin >> N >> D;

    Road road[N];
    for(int i = 0; i < N; i++) {
        cin >> road[i].start >> road[i].end >> road[i].length;
    }

    sort(road, road + N, cmp);

    int dp[D + 1];
    dp[0] = 0;

    for(int i = 0; i <= D; i++) {
        if (i > 0) {
            dp[i] = dp[i - 1] + 1;
        }

        for(int j = 0; j < N; j++) {
            if(road[j].end == i) {
                if (road[j].start < i) {
                    dp[i] = min(dp[i], dp[road[j].start] + road[j].length); // 지름길을 이용하는 경우
                }
            }
        }
    }

    cout << dp[D] << endl;
}