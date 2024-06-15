#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

const int INF = 1e9 + 7;
int n, m, x;
vector<pair<int, int>> graph[2][1001]; // 양방향 그래프
vector<int> dist[2]; // 각 마을에서 출발했을 때의 최단 거리

void dijkstra(int start, int direction) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[direction][start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (curr_dist > dist[direction][curr_node]) continue;

        for (auto& next : graph[direction][curr_node]) {
            int next_node = next.second;
            int next_dist = curr_dist + next.first;

            if (next_dist < dist[direction][next_node]) {
                dist[direction][next_node] = next_dist;
                pq.emplace(next_dist, next_node);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[0][a].emplace_back(t, b); // 양방향 그래프
        graph[1][b].emplace_back(t, a);
    }

    dist[0].resize(n + 1, INF);
    dist[1].resize(n + 1, INF);

    dijkstra(x, 0); // x에서 출발
    dijkstra(x, 1); // x로 돌아오는 경우

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        result = max(result, dist[0][i] + dist[1][i]);
    }

    cout << result << '\n';

    return 0;
}