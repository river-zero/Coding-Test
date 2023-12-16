class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1000000007;
        vector<long long> dp(max(n + 1, 4), 0);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }

        return static_cast<int>(dp[n]);
    }
};