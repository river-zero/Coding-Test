#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> indegree(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        vector<int> seq(k);
        for (int j = 0; j < k; j++) {
            cin >> seq[j];
        }
        for (int j = 0; j < k - 1; j++) {
            adj[seq[j]].push_back(seq[j + 1]);
            indegree[seq[j + 1]]++;
        }
    }

    queue<int> q;
    vector<int> result;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);
        for (int next : adj[current]) {
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }

    if (result.size() != N) {
        cout << 0 << "\n";
    } else {
        for (int num : result) {
            cout << num << "\n";
        }
    }

    return 0;
}
