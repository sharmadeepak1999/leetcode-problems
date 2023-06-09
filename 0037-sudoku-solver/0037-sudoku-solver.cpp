class Solution {
    bool isSafe(vector<vector<char>> &board, int row, int col, char k) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == k) return false;
            if(board[i][col] == k) return false;
            // if(board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == k) return false;
        }
        for(int i = (row / 3) * 3; i <= (row / 3) * 3 + 2; i++) {
            for(int j = (col / 3) * 3; j <= ((col / 3) * 3) + 2; j++) {
                if(board[i][j] == k) return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>> &board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char k = '1'; k <= '9'; k++) {
                        if(isSafe(board, i, j, k)) {
                            board[i][j] = k;
                            if(helper(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};