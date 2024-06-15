#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, E, v1, v2;
vector<pair<int, int>> graph[801];
int dist[801];

void dijkstra(int start) {
    fill(dist, dist + 801, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int current = pq.top().second;
        int current_dist = pq.top().first;
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
    cin >> N >> E;

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    dijkstra(1);
    int sToV1 = dist[v1];
    int sToV2 = dist[v2];

    dijkstra(v1);
    int V1ToV2 = dist[v2];
    int V1ToN = dist[N];

    dijkstra(v2);
    int V2ToN = dist[N];

    int result = INF;

    if (sToV1 != INF && V1ToV2 != INF && V2ToN != INF) {
        result = min(result, sToV1 + V1ToV2 + V2ToN);
    }

    if (sToV2 != INF && V1ToV2 != INF && V1ToN != INF) {
        result = min(result, sToV2 + V1ToV2 + V1ToN);
    }

    if (result >= INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
