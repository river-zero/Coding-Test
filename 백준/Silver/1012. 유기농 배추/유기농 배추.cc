#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int x, int y, vector<vector<int>> &field) {
    field[x][y] = 0;
    
    int m = field.size();
    int n = field[0].size();
    int xpos[4] = {0, 0, -1, 1};
    int ypos[4] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int xx = x + xpos[i];
        int yy = y + ypos[i];
        
        // 범위를 벗어나는 경우 무시
        if (xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
        
        // 방문하지 않은 땅이라면 재귀적으로 탐색
        if (field[xx][yy] == 1) dfs(xx, yy, field);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        
        // 배추 위치 입력
        vector<vector<int>> field(m, vector<int>(n, 0));
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 배추가 심어져 있는 땅을 발견하면 연결된 배추들을 모두 탐색
                if (field[i][j] == 1) {
                    dfs(i, j, field);
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }
}
