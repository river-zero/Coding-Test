#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if (x != y) {
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    // 간선을 비용 기준으로 정렬
    sort(edges.begin(), edges.end());

    // 유니온-파인드 자료구조 초기화
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int mst_cost = 0;
    int max_edge_cost = 0;
    int edges_used = 0;

    for (const auto& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            unite(parent, rank, edge.u, edge.v);
            mst_cost += edge.cost;
            max_edge_cost = edge.cost;
            edges_used++;
            if (edges_used == n - 1) break;
        }
    }

    // 가장 비용이 큰 간선 제거
    mst_cost -= max_edge_cost;

    cout << mst_cost << '\n';

    return 0;
}
