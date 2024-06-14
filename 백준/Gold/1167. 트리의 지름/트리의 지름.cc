#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int index;
    int dist;
    Node(int i, int d) : index(i), dist(d) {}
};

int V, maxDist, maxNode;
bool visited[100001];
vector<Node> graph[100001];

void dfs(int node, int dist) {
    if (visited[node]) return;

    visited[node] = true;
    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }

    for (const Node& next : graph[node]) {
        dfs(next.index, dist + next.dist);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V;
    int from, to, distance;
    for (int i = 1; i <= V; i++) {
        cin >> from;
        while (true) {
            cin >> to;
            if (to == -1) break;
            cin >> distance;
            graph[from].emplace_back(to, distance);
            graph[to].emplace_back(from, distance);
        }
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(maxNode, 0);

    cout << maxDist << '\n';

    return 0;
}