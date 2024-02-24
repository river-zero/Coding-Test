#include <iostream>
#include <vector>

using namespace std;

int dfs(int node, vector<bool> &visited, vector<vector<int>> &graph, int count) {
    count++;
    visited[node] = true;

    for (int i : graph[node]) {
        if (!visited[i]) {
            count = dfs(i, visited, graph, count);
        }
    }

    return count;
}

int main() {
    int a, b;
    cin >> a >> b;

    vector<bool> visited(a + 1, false);
    vector<vector<int>> graph(a + 1);
    
    for (int i = 0; i < b; i++) {
        int c, d;
        cin >> c >> d;
        graph[c].push_back(d);
        graph[d].push_back(c);
    }

    int cnt = 0;
    cout << dfs(1, visited, graph, cnt) - 1;
}
