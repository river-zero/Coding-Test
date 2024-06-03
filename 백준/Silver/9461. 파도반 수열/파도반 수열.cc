#include <iostream>
#include <vector>
using namespace std;

long long dp[101];

long long padovan(int n) {
    if (dp[n] != 0) {
        return dp[n];
    }

    dp[n] = padovan(n - 1) + padovan(n - 5);
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    while (T--) {
        int N;
        cin >> N;

        cout << padovan(N) << '\n';
    }

    return 0;
}