class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> table(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cell = board[i][j];
                if (cell == '.') {
                    continue;
                }
                
                // 중복인 경우
                if (row[i].count(cell) || col[j].count(cell) || table[i / 3 * 3 + j / 3].count(cell)) {
                    return false;
                }
                
                // 중복이 없는 경우
                row[i].insert(cell);
                col[j].insert(cell);
                table[i / 3 * 3 + j / 3].insert(cell);
            }
        }
        
        return true;
    }
};