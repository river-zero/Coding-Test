#include <iostream>
#include <queue>
using namespace std;

struct Tomato {
    int z, y, x;
};

int M, N, H;
int box[100][100][100];
int dz[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {1, -1, 0, 0, 0, 0};

int bfs() {
    queue<Tomato> q;
    int days = 0;

    // 초기에 익은 토마토의 위치를 큐에 삽입
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 1) {
                    q.push({i, j, k});
                }
            }
        }
    }

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Tomato t = q.front();
            q.pop();

            // 6방향으로 인접한 토마토 익히기
            for (int j = 0; j < 6; j++) {
                int newZ = t.z + dz[j];
                int newY = t.y + dy[j];
                int newX = t.x + dx[j];

                if (newZ >= 0 && newZ < H && newY >= 0 && newY < N && newX >= 0 && newX < M) {
                    if (box[newZ][newY][newX] == 0) {
                        box[newZ][newY][newX] = 1;
                        q.push({newZ, newY, newX});
                    }
                }
            }
        }

        days++;
    }

    // 모든 토마토가 익었는지 확인
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    return -1;
                }
            }
        }
    }

    return days - 1;
}

int main() {
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
            }
        }
    }

    int result = bfs();
    cout << result << endl;

    return 0;
}