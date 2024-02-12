#include <string>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &computers, vector<bool> &visited) {
    // 현재 노드 방문 표시
    visited[node] = true;
    
    for (int i = 0; i < computers.size(); i++) {
        // 연결돼 있고 방문하지 않았다면 이동해 재귀로 탐색
        if (computers[node][i] == 1 && !visited[i]) {
            dfs(i, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, computers, visited);
            answer++;
        }
    }

    return answer;
}
