#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();
        result.push_back(current);

        for (int next : adj[current]) {
            in_degree[next]--;
            if (in_degree[next] == 0) {
                pq.push(next);
            }
        }
    }

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
