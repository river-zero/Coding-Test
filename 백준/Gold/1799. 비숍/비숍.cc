#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int board[10][10];
bool used1[20], used2[20];
int max_bishops[2];

void placeBishops(int r, int c, int color, int count) {
    if (c >= N) {
        r++;
        c = (c % 2 == 0) ? 1 : 0;
    }

    if (r >= N) {
        max_bishops[color] = max(max_bishops[color], count);
        return;
    }

    if (board[r][c] && !used1[r + c] && !used2[r - c + N - 1]) {
        used1[r + c] = true;
        used2[r - c + N - 1] = true;
        placeBishops(r, c + 2, color, count + 1);
        used1[r + c] = false;
        used2[r - c + N - 1] = false;
    }

    placeBishops(r, c + 2, color, count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    memset(used1, 0, sizeof(used1));
    memset(used2, 0, sizeof(used2));
    placeBishops(0, 0, 0, 0);

    memset(used1, 0, sizeof(used1));
    memset(used2, 0, sizeof(used2));
    placeBishops(0, 1, 1, 0);

    cout << max_bishops[0] + max_bishops[1] << '\n';

    return 0;
}
