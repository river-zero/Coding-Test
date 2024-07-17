#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> build_time(n + 1);
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> build_time[i];
    }

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        indegree[y]++;
    }

    int target;
    cin >> target;

    queue<int> q;
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i] = build_time[i];
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            dp[next] = max(dp[next], dp[curr] + build_time[next]);
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << dp[target] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
