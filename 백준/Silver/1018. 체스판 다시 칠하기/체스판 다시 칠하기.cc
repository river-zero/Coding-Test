#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CountRepaint(const vector<string> &board, int startRow, int startCol) {
    int repaintNum = 0;
    char startColor = board[startRow][startCol];
    
    for (int i = startRow; i < startRow + 8; i++) {
        for (int j = startCol; j < startCol + 8; j++) {
            if (board[i][j] != startColor) repaintNum++;
            
            // 다음 칸은 색깔 변경
            startColor = (startColor == 'W') ? 'B' : 'W';
        }
        
        // 줄이 바뀌면 색깔 변경
        startColor = (startColor == 'W') ? 'B' : 'W';
    }
    
    return repaintNum;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int minRepaint = 64;

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            minRepaint = min(minRepaint, min(CountRepaint(board, i, j), 64 - CountRepaint(board, i, j)));
        }
    }

    cout << minRepaint;
}