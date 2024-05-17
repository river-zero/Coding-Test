#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_USERS = 100;

int bfs(int start, int N, const vector<vector<int>>& graph) {
    vector<int> distance(N + 1, -1);
    queue<int> q;
    
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int next : graph[curr]) {
            if (distance[next] == -1) {
                distance[next] = distance[curr] + 1;
                q.push(next);
            }
        }
    }
    
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += distance[i];
    }
    
    return sum;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N + 1);
    
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    int minKB = MAX_USERS * MAX_USERS;
    int minUser = 0;
    
    for (int i = 1; i <= N; i++) {
        int kb = bfs(i, N, graph);
        if (kb < minKB) {
            minKB = kb;
            minUser = i;
        }
    }
    
    cout << minUser << endl;
    
    return 0;
}