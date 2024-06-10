#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<string> campus;
vector<vector<bool>> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt = 0;

void dfs(int x, int y) {
    visited[x][y] = true;
    
    if (campus[x][y] == 'P') {
        cnt++;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && campus[nx][ny] != 'X') {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    campus.resize(n);
    visited.resize(n, vector<bool>(m, false));

    int startX = -1, startY = -1;
    for (int i = 0; i < n; i++) {
        cin >> campus[i];
        for (int j = 0; j < m; j++) {
            if (campus[i][j] == 'I') {
                startX = i;
                startY = j;
            }
        }
    }

    if (startX != -1 && startY != -1) {
        dfs(startX, startY);
    }

    if (cnt == 0) {
        cout << "TT" << '\n';
    } else {
        cout << cnt << '\n';
    }

    return 0;
}