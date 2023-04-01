class Solution {
public:
    bool canPlace(vector<vector<char>> &board, int i, int j, char n) {
        for(int k = 0; k < 9; k++) {
            if(board[i][k] == n) return false;
            if(board[k][j] == n) return false;
            if(board[3 * (i / 3) + (k / 3)][3 * (j / 3) + (k % 3)] == n) return false;

        }
        
        return true;
    }
    bool helper(vector<vector<char>> &board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char k = '1'; k <= '9'; k++) {
                        if(canPlace(board, i, j, k)) {
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
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};