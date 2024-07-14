#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 8;
int N, M;
int lab[MAX][MAX];
int temp[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs() {
    int result = 0;
    int virus[MAX][MAX];
    queue<pair<int, int>> q;

    // 바이러스 위치 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            virus[i][j] = temp[i][j];
            if (virus[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    // 바이러스 확산
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (virus[nx][ny] == 0) {
                    virus[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }

    // 안전 영역 크기 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (virus[i][j] == 0) {
                result++;
            }
        }
    }

    return result;
}

void copyMap(int (*a)[MAX], int (*b)[MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = b[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
        }
    }

    int maxSafeArea = 0;

    // 모든 경우의 수로 벽 세우기
    for (int i = 0; i < N * M; i++) {
        for (int j = i + 1; j < N * M; j++) {
            for (int k = j + 1; k < N * M; k++) {
                int x1 = i / M, y1 = i % M;
                int x2 = j / M, y2 = j % M;
                int x3 = k / M, y3 = k % M;

                if (lab[x1][y1] == 0 && lab[x2][y2] == 0 && lab[x3][y3] == 0) {
                    lab[x1][y1] = 1;
                    lab[x2][y2] = 1;
                    lab[x3][y3] = 1;

                    copyMap(temp, lab);
                    maxSafeArea = max(maxSafeArea, bfs());

                    lab[x1][y1] = 0;
                    lab[x2][y2] = 0;
                    lab[x3][y3] = 0;
                }
            }
        }
    }

    cout << maxSafeArea << '\n';

    return 0;
}
