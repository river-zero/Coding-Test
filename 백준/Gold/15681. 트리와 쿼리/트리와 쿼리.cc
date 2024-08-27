#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> subtree_size;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    subtree_size[node] = 1; 
    for (int child : tree[node]) {
        if (!visited[child]) {
            subtree_size[node] += dfs(child);
        }
    }
    return subtree_size[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, R, Q;
    cin >> N >> R >> Q;
    tree.resize(N + 1);
    subtree_size.resize(N + 1, 0);
    visited.resize(N + 1, false);

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(R); 

    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        cout << subtree_size[query] << '\n';
    }

    return 0;
}
