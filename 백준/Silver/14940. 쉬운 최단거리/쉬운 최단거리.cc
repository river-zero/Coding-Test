#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

void bfs(vector<vector<int>> &map, vector<vector<int>> &dist, pair<int, int> &start) {
    int N = map.size();
    int M = map[0].size();

    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 내이고, 갈 수 있고, 아직 가지 않은 곳인 경우
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != 0 && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M, INF));
    pair<int, int> start;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2)
                start = make_pair(i, j);
        }
    }

    bfs(map, dist, start);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) cout << 0 << " ";
            else if (dist[i][j] == INF) cout << -1 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
