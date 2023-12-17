class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshOranges = 0;
        int minutes = 0;

        // BFS를 위한 큐
        queue<pair<int, int>> rottenOranges;

        // 초기 상태에서 신선한 오렌지의 수와 썩은 오렌지의 위치를 파악
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                } else if (grid[i][j] == 2) {
                    rottenOranges.push({i, j});
                }
            }
        }

        // 주변 오렌지를 감염시키는 BFS
        while (!rottenOranges.empty() && freshOranges > 0) {
            int size = rottenOranges.size();

            for (int i = 0; i < size; i++) {
                int x = rottenOranges.front().first;
                int y = rottenOranges.front().second;
                rottenOranges.pop();

                // 상
                rotAdjacent(grid, rottenOranges, x - 1, y, freshOranges);
                // 하
                rotAdjacent(grid, rottenOranges, x + 1, y, freshOranges);
                // 좌
                rotAdjacent(grid, rottenOranges, x, y - 1, freshOranges);
                // 우
                rotAdjacent(grid, rottenOranges, x, y + 1, freshOranges);
            }

            minutes++;
        }

        return (freshOranges == 0) ? minutes : -1;
    }

private:
    // 주어진 좌표 주변의 오렌지를 감염시키는 함수
    void rotAdjacent(vector<vector<int>>& grid, queue<pair<int, int>>& rottenOranges, int x, int y, int& freshOranges) {
        int rows = grid.size();
        int cols = grid[0].size();

        // 좌표가 유효하고 신선한 오렌지라면 감염 처리
        if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1) {
            grid[x][y] = 2;
            rottenOranges.push({x, y});
            freshOranges--;
        }
    }
};