#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int INF = 1e9 + 7;

struct Edge {
    int to, cost;
};

vector<int> dijkstra(int start, vector<vector<Edge>>& graph, vector<int>& parent) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode]) continue;

        for (const Edge& edge : graph[currentNode]) {
            int nextNode = edge.to;
            int nextDist = currentDist + edge.cost;

            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                parent[nextNode] = currentNode;
                pq.push({nextDist, nextNode});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
    }

    int start, end;
    cin >> start >> end;

    vector<int> parent(n + 1, -1);
    vector<int> dist = dijkstra(start, graph, parent);

    cout << dist[end] << '\n';

    stack<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push(v);
    }

    cout << path.size() << '\n';
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << '\n';

    return 0;
}
