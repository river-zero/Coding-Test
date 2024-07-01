#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<bool> visited;
vector<vector<int>> tree;

void dfs(int node) {
    visited[node] = true;
    for (int next : tree[node]) {
        if (!visited[next]) {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    tree.resize(n + 1);
    parent.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= n; ++i) {
        cout << parent[i] << '\n';
    }

    return 0;
}
