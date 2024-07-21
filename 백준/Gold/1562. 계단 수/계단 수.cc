#include <iostream>
#include <vector>
#define MOD 1000000000

using namespace std;

int main() {
    int N;
    cin >> N;

    // dp[i][j][k] = i자리 계단수에서 마지막 숫자가 j이고 k 상태인 경우의 수
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(10, vector<long long>(1 << 10, 0)));

    // 초기 상태: 한 자리 수 (1~9)
    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    // DP 계산
    for (int len = 1; len < N; len++) {
        for (int last = 0; last <= 9; last++) {
            for (int mask = 0; mask < (1 << 10); mask++) {
                if (dp[len][last][mask] == 0) continue;

                // 다음 숫자가 last - 1인 경우
                if (last > 0) {
                    int next_mask = mask | (1 << (last - 1));
                    dp[len + 1][last - 1][next_mask] = (dp[len + 1][last - 1][next_mask] + dp[len][last][mask]) % MOD;
                }
                // 다음 숫자가 last + 1인 경우
                if (last < 9) {
                    int next_mask = mask | (1 << (last + 1));
                    dp[len + 1][last + 1][next_mask] = (dp[len + 1][last + 1][next_mask] + dp[len][last][mask]) % MOD;
                }
            }
        }
    }

    // 결과 계산
    long long result = 0;
    for (int last = 0; last <= 9; last++) {
        result = (result + dp[N][last][(1 << 10) - 1]) % MOD;
    }

    cout << result << endl;

    return 0;
}
