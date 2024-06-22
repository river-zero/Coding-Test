#include <iostream>
#include <vector>

using namespace std;

void drawStars(vector<vector<char>>& board, int x, int y, int size) {
    if (size == 3) {
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        for (int i = -2; i <= 2; ++i) {
            board[x + 2][y + i] = '*';
        }
        return;
    }
    
    int newSize = size / 2;
    drawStars(board, x, y, newSize);
    drawStars(board, x + newSize, y - newSize, newSize);
    drawStars(board, x + newSize, y + newSize, newSize);
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<char>> board(n, vector<char>(2 * n - 1, ' '));
    
    drawStars(board, 0, n - 1, n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
