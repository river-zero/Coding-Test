#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
vector<string> board;
bool visited[26]; // 알파벳 방문 체크
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우 이동
int dy[4] = { 0, 0, -1, 1 }; // 상하좌우 이동
int maxCount = 0;

void dfs(int x, int y, int count) {
    maxCount = max(maxCount, count);

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            char nextChar = board[nx][ny];
            if (!visited[nextChar - 'A']) {
                visited[nextChar - 'A'] = true;
                dfs(nx, ny, count + 1);
                visited[nextChar - 'A'] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    board.resize(R);
    for (int i = 0; i < R; ++i) {
        cin >> board[i];
    }

    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << maxCount << "\n";

    return 0;
}
