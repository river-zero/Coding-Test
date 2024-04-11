#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[50][50];
int N, M;

int main() {
    int r, c, d;
    cin >> N >> M >> r >> c >> d;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    int cnt = 0;
    while (true) {
        if (map[r][c] == 0) {
            map[r][c] = 2;
            cnt++;
        }

        bool flag = false;
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (map[nr][nc] == 0) {
                r = nr;
                c = nc;
                flag = true;
                break;
            }
        }

        if (!flag) {
            if (map[r - dx[d]][c - dy[d]] == 1)
                break;
            else {
                r = r - dx[d];
                c = c - dy[d];
            }
        }
    }

    cout << cnt << '\n';
}
