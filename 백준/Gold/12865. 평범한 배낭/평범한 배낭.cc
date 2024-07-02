#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> weight(N + 1);
    vector<int> value(N + 1);
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= N; ++i) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int w = 0; w <= K; ++w) {
            if (w < weight[i]) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i]);
            }
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}
