#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sticker[2][100001];
        int dp[2][100001] = {0};

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> sticker[i][j];
            }
        }

        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];

        for (int j = 1; j < n; ++j) {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + sticker[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + sticker[1][j];
        }

        int result = max(dp[0][n - 1], dp[1][n - 1]);
        cout << result << '\n';
    }
    return 0;
}
