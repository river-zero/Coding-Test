#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n, m, r;
vector<int> items;
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (cost > dist[here]) continue;

        for (auto &next : graph[here]) {
            int there = next.first;
            int nextDist = cost + next.second;

            if (nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push({nextDist, there});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> r;
    items.resize(n + 1);
    graph.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> items[i];
    }

    for (int i = 0; i < r; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    int maxItems = 0;

    for (int i = 1; i <= n; ++i) {
        vector<int> dist = dijkstra(i);
        int itemsCollected = 0;

        for (int j = 1; j <= n; ++j) {
            if (dist[j] <= m) {
                itemsCollected += items[j];
            }
        }

        maxItems = max(maxItems, itemsCollected);
    }

    cout << maxItems << '\n';

    return 0;
}
