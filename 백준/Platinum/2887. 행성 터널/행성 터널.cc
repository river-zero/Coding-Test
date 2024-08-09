#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int cost;
    int from;
    int to;
};

int N;
vector<pair<int, int>> coords[3];
vector<Edge> edges;
int parent[100001];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unionFind(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[a] = b;
}

long long kruskal() {
    long long totalCost = 0;
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.cost < b.cost;
    });

    for (auto &edge : edges) {
        if (find(edge.from) != find(edge.to)) {
            unionFind(edge.from, edge.to);
            totalCost += edge.cost;
        }
    }
    return totalCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        coords[0].push_back({x, i});
        coords[1].push_back({y, i});
        coords[2].push_back({z, i});
        parent[i] = i;
    }

    for (int i = 0; i < 3; i++) {
        sort(coords[i].begin(), coords[i].end());
        for (int j = 0; j < N - 1; j++) {
            edges.push_back({abs(coords[i][j].first - coords[i][j+1].first), coords[i][j].second, coords[i][j+1].second});
        }
    }

    cout << kruskal() << endl;
    return 0;
}
