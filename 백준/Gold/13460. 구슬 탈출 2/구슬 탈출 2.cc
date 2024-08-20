#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct State {
    int red_row, red_col, blue_row, blue_col, count;
};

const int MAX = 10;
int N, M;
char board[11][11];

int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // Right, Down, Left, Up

bool in_range(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

pair<int, int> move_until_blocked(int x, int y, int dx, int dy) {
    while (in_range(x + dx, y + dy) && board[x + dx][y + dy] != '#' && board[x][y] != 'O') {
        x += dx;
        y += dy;
    }
    return {x, y};
}

int bfs(int r_row, int r_col, int b_row, int b_col) {
    queue<State> q;
    vector<vector<vector<vector<bool>>>> visited(N, vector<vector<vector<bool>>>(M, vector<vector<bool>>(N, vector<bool>(M, false))));
    q.push({r_row, r_col, b_row, b_col, 0});
    visited[r_row][r_col][b_row][b_col] = true;

    while (!q.empty()) {
        State current = q.front(); q.pop();
        if (current.count > 10) break;
        if (board[current.red_row][current.red_col] == 'O' && board[current.blue_row][current.blue_col] != 'O') {
            return current.count;
        }

        for (auto& dir : directions) {
            int dx = dir[0], dy = dir[1];
            auto [n_r_row, n_r_col] = move_until_blocked(current.red_row, current.red_col, dx, dy);
            auto [n_b_row, n_b_col] = move_until_blocked(current.blue_row, current.blue_col, dx, dy);

            if (n_r_row == n_b_row && n_r_col == n_b_col) {
                if (board[n_r_row][n_r_col] == 'O') continue;  // Both at the hole
                if (abs(n_r_row - current.red_row) + abs(n_r_col - current.red_col) > abs(n_b_row - current.blue_row) + abs(n_b_col - current.blue_col)) {
                    n_r_row -= dx;
                    n_r_col -= dy;
                } else {
                    n_b_row -= dx;
                    n_b_col -= dy;
                }
            }
            
            if (!visited[n_r_row][n_r_col][n_b_row][n_b_col]) {
                visited[n_r_row][n_r_col][n_b_row][n_b_col] = true;
                q.push({n_r_row, n_r_col, n_b_row, n_b_col, current.count + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> M;
    int r_row, r_col, b_row, b_col;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                r_row = i;
                r_col = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'B') {
                b_row = i;
                b_col = j;
                board[i][j] = '.';
            }
        }
    }

    int answer = bfs(r_row, r_col, b_row, b_col);
    cout << answer << endl;
    return 0;
}
