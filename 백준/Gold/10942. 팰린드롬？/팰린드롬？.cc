#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = true;
        if (i < n && arr[i] == arr[i+1]) {
            dp[i][i+1] = true;
        }
    }

    for (int length = 3; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            if (arr[i] == arr[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
            }
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << (dp[s][e] ? 1 : 0) << '\n';
    }

    return 0;
}
