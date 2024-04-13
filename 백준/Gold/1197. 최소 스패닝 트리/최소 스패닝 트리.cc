#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, w;
    edge() : edge(-1, -1, 0) {}
    edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator <(const edge& e) const { return w < e.w; }
};

int parent[10001];

int find(int a) {
    if (parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;
    vector<edge> edges;
    fill(parent, parent + v + 1, -1);
    
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(edge(u, v, w));
    }
    sort(edges.begin(), edges.end());

    int result = 0;
    for (auto &edge: edges) {
        if (merge(edge.u, edge.v)) {
            result += edge.w;
        }
    }
    cout << result << '\n';
}
