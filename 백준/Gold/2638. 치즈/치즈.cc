#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
int board[100][100];
bool visited[100][100];

bool isInBounds(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfsAirExposure() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInBounds(nx, ny) && !visited[nx][ny] && board[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int countAirExposedSides(int x, int y) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isInBounds(nx, ny) && visited[nx][ny]) {
            count++;
        }
    }
    return count;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    int time = 0;
    while (true) {
        memset(visited, false, sizeof(visited));
        bfsAirExposure();

        vector<pair<int, int>> toMelt;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 1 && countAirExposedSides(i, j) >= 2) {
                    toMelt.push_back({i, j});
                }
            }
        }

        if (toMelt.empty()) {
            break;
        }

        for (auto& cell : toMelt) {
            board[cell.first][cell.second] = 0;
        }

        time++;
    }

    cout << time << '\n';

    return 0;
}
