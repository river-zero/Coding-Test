#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> cost(N + 1, vector<int>(3));
    for (int i = 1; i <= N; ++i) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    int answer = INF;

    for (int first = 0; first < 3; ++first) {
        vector<vector<int>> dp(N + 1, vector<int>(3, INF));
        dp[1][first] = cost[1][first];

        for (int i = 2; i <= N; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (j != k) { 
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + cost[i][j]);
                    }
                }
            }
        }

        for (int last = 0; last < 3; ++last) {
            if (last != first) {
                answer = min(answer, dp[N][last]);
            }
        }
    }

    cout << answer << endl;

    return 0;
}
