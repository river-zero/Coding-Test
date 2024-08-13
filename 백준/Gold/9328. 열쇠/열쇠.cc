#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 105;
int h, w;
char building[MAX][MAX];
bool visited[MAX][MAX];
bool keys[26];
vector<pair<int, int>> doors[26];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= h + 2 || ny >= w + 2) continue;
            if (visited[nx][ny] || building[nx][ny] == '*') continue;
            visited[nx][ny] = true;

            if (islower(building[nx][ny])) {
                int key = building[nx][ny] - 'a';
                keys[key] = true;
                for (auto& door : doors[key]) {
                    q.push(door);
                }
                doors[key].clear();
            } else if (isupper(building[nx][ny])) {
                int door = building[nx][ny] - 'A';
                if (!keys[door]) {
                    doors[door].push_back({nx, ny});
                    continue;
                }
            }

            q.push({nx, ny});
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> h >> w;
        memset(building, '.', sizeof(building));
        memset(visited, false, sizeof(visited));
        memset(keys, false, sizeof(keys));
        for (int i = 0; i < 26; i++) doors[i].clear();

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> building[i][j];
            }
        }

        string initialKeys;
        cin >> initialKeys;
        if (initialKeys != "0") {
            for (char key : initialKeys) {
                keys[key - 'a'] = true;
            }
        }

        h += 2; w += 2;
        int documentCount = 0;
        bfs();
        
        for (int i = 1; i < h - 1; i++) {
            for (int j = 1; j < w - 1; j++) {
                if (building[i][j] == '$' && visited[i][j]) {
                    documentCount++;
                }
            }
        }

        cout << documentCount << "\n";
    }
    return 0;
}
