#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;
int n;
int cost[16][16];
int dp[1 << 16][16];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0] ? cost[pos][0] : INF;
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int result = INF;
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0 && cost[pos][city]) {
            int newResult = cost[pos][city] + tsp(mask | (1 << city), city);
            result = min(result, newResult);
        }
    }

    return dp[mask][pos] = result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int result = tsp(1, 0);
    cout << result << '\n';

    return 0;
}
