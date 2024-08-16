#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> r(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i] >> c[i];
    }

    vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    for (int len = 2; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + r[i] * c[k] * c[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << dp[0][N-1] << endl; 
    return 0;
}
