#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> memory(N), cost(N);
    for (int i = 0; i < N; i++) {
        cin >> memory[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    int maxCost = 10000;
    vector<int> dp(maxCost + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = maxCost; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }

    for (int i = 0; i <= maxCost; i++) {
        if (dp[i] >= M) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
