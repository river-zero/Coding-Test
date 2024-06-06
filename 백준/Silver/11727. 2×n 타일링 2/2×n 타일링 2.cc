#include <iostream>
using namespace std;

const int MOD = 10007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int dp[1001] = {0};
    dp[1] = 1;
    dp[2] = 3;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % MOD;
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}