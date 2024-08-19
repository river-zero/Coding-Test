#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int result = 0;

vector<vector<int>> rotate90(vector<vector<int>>& board) {
    vector<vector<int>> rotated(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[j][N-1-i] = board[i][j];
        }
    }
    return rotated;
}

vector<vector<int>> moveLeft(vector<vector<int>>& original) {
    vector<vector<int>> board = original;
    for (int i = 0; i < N; i++) {
        vector<int> line;
        for (int j = 0; j < N; j++) {
            if (board[i][j]) line.push_back(board[i][j]);
        }
        for (int j = 0; j < line.size(); j++) {
            if (j + 1 < line.size() && line[j] == line[j + 1]) {
                line[j] *= 2;
                line[j + 1] = 0;
                j++;
            }
        }
        line.erase(remove(line.begin(), line.end(), 0), line.end());
        line.resize(N, 0);
        for (int j = 0; j < N; j++) {
            board[i][j] = line[j];
        }
    }
    return board;
}

void dfs(vector<vector<int>>& board, int depth) {
    if (depth == 5) {
        for (auto& row : board) {
            for (auto& num : row) {
                result = max(result, num);
            }
        }
        return;
    }
    for (int dir = 0; dir < 4; dir++) {
        vector<vector<int>> new_board = moveLeft(board);
        dfs(new_board, depth + 1);
        board = rotate90(board);
    }
}

int main() {
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    dfs(board, 0);
    cout << result << endl;
    return 0;
}
