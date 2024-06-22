#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INF)));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    dist[0][0][0] = 1;

    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (map[nx][ny] == 0 && dist[nx][ny][broken] > dist[x][y][broken] + 1) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.emplace(nx, ny, broken);
            }

            if (!broken && map[nx][ny] == 1 && dist[nx][ny][1] > dist[x][y][0] + 1) {
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.emplace(nx, ny, 1);
            }
        }
    }

    int answer = min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    if (answer == INF) answer = -1;

    cout << answer << '\n';

    return 0;
}
