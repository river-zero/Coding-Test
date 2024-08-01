#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> zeros;

bool check(int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num) return false;
        if (board[i][col] == num) return false;
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (board[i][j] == num) return false;
        }
    }
    return true;
}

bool solve(int index = 0) {
    if (index == zeros.size()) return true;
    int row = zeros[index].first;
    int col = zeros[index].second;

    for (int num = 1; num <= 9; ++num) {
        if (check(row, col, num)) {
            board[row][col] = num;
            if (solve(index + 1)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char input;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> input;
            board[i][j] = input - '0';
            if (board[i][j] == 0) {
                zeros.push_back({i, j});
            }
        }
    }

    solve();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
