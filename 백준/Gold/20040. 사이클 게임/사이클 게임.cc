#include <iostream>
using namespace std;

int parent[500000];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool union_sets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) return true;

    parent[rootA] = rootB;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        if (union_sets(u, v)) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';

    return 0;
}
