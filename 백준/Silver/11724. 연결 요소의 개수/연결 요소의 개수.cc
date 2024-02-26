#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<int> &visited) {
    visited[node] = 1;
    
    for (int i = 0; i < graph[node].size(); i++) {
        int index = graph[node][i];
        if (visited[index] == 0) dfs(index, graph, visited);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N + 1);
    vector<int> visited(N + 1, 0);
    
    int u, v;
    for (int i = 0; i < M; i++) {
        // 무방향 그래프이므로 양쪽에 간선 추가
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            count++;
            dfs(i, graph, visited);
        }
    }
    
    cout << count << endl;
}