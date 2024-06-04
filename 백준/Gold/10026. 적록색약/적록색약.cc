#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

char grid[MAX][MAX];
bool visited[MAX][MAX];
int N;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, char color, bool isColorBlind) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
            if (isColorBlind && (color == 'R' || color == 'G')) {
                if (grid[nx][ny] == 'R' || grid[nx][ny] == 'G') {
                    dfs(nx, ny, color, isColorBlind);
                }
            } else if (grid[nx][ny] == color) {
                dfs(nx, ny, color, isColorBlind);
            }
        }
    }
}

int countAreas(bool isColorBlind) {
    int count = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j], isColorBlind);
                count++;
            }
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int normalCount = countAreas(false);
    int colorBlindCount = countAreas(true);

    cout << normalCount << " " << colorBlindCount << '\n';

    return 0;
}