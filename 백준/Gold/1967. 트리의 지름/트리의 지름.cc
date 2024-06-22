#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10001;

vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int maxDist = 0;
int farthestNode = 0;

void dfs(int node, int dist) {
    visited[node] = true;
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }
    for (auto &edge : tree[node]) {
        int nextNode = edge.first;
        int weight = edge.second;
        if (!visited[nextNode]) {
            dfs(nextNode, dist + weight);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        tree[child].push_back({parent, weight});
    }

    // 첫 번째 DFS: 임의의 노드(1번 노드)에서 가장 먼 노드를 찾음
    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    // 두 번째 DFS: 가장 먼 노드에서 가장 먼 노드를 찾음
    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(farthestNode, 0);

    cout << maxDist << "\n";

    return 0;
}
