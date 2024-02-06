#include <string>
#include <vector>

using namespace std;

// 깊이 우선 탐색 함수
int dfs(int cnt, int k, vector<bool> &visited, vector<vector<int>> &dungeons) {
    // 현재까지 탐색한 던전 수
    int answer = cnt;

    for (int i = 0; i < dungeons.size(); i++) {
        // 아직 방문하지 않았고 갈 수 있는 경우
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            
            // 다음 던전으로 이동
            int next_count = dfs(cnt + 1, k - dungeons[i][1], visited, dungeons);
            
            // 현재까지의 탐험 던전 수와 다음 탐험 던전 수 중 최댓값 선택
            answer = max(answer, next_count);
            
            // 다른 탐색을 위한 백트래킹
            visited[i] = false;
        }
    }

    return answer;
}

int solution(int k, vector<vector<int>> dungeons) {
    int n = dungeons.size();
    vector<bool> visited(n, false);
    return dfs(0, k, visited, dungeons);
}
