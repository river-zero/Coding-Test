#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int INF = 1e9;
int V, E, start;
vector<pair<int, int>> graph[20001];
vector<int> dist(20001, INF);

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < current_dist) continue;

        for (auto &edge : graph[current]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > dist[current] + weight) {
                dist[next] = dist[current] + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;
    cin >> start;

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dijkstra(start);

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}
