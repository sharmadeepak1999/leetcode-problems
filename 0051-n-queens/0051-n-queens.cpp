class Solution {
public:
    bool canPlace(vector<string> board, int n, int row, int col) {
        for(int i = row - 1; i >= 0; i--) {
            if(board[i][col] == 'Q') return false;
        }
        
        for(int j = col - 1; j >= 0; j--) {
            if(board[row][j] == 'Q') return false;
        }
        
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void helper(vector<vector<string>> &ans, vector<string> &board, int n, int row) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int j = 0; j < n; j++) {
            if(canPlace(board, n, row, j)) {
                board[row][j] = 'Q';
                helper(ans, board, n, row + 1);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        helper(ans, board, n, 0);
        return ans;
    }
};