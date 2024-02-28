#include <iostream>
#include <vector>

using namespace std;

pair<int, int> CheckColor(const vector<vector<int>> &paper, int row, int col, int size) {
    int whiteCount = 0;
    int blueCount = 0;

    // 현재 종이의 색상을 확인
    int color = paper[row][col];

    // 현재 종이의 색상과 다른 색깔이 있는지 확인
    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            if (paper[i][j] != color) {
                // 다른 색이 있다면 나눠서 재귀로 또 확인
                pair<int, int> upperLeft = CheckColor(paper, row, col, size / 2);
                pair<int, int> upperRight = CheckColor(paper, row, col + size / 2, size / 2);
                pair<int, int> lowerLeft = CheckColor(paper, row + size / 2, col, size / 2);
                pair<int, int> lowerRight = CheckColor(paper, row + size / 2, col + size / 2, size / 2);

                // 흰색과 파란색 개수를 합산
                whiteCount = upperLeft.first + upperRight.first + lowerLeft.first + lowerRight.first;
                blueCount = upperLeft.second + upperRight.second + lowerLeft.second + lowerRight.second;

                return {whiteCount, blueCount};
            }
        }
    }

    // 모두 하얗거나 파란색인 경우
    if (color == 0) whiteCount = 1;
    else blueCount = 1;

    return {whiteCount, blueCount};
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    pair<int, int> result = CheckColor(paper, 0, 0, N);

    cout << result.first << '\n';  
    cout << result.second << '\n'; 
}
