class Solution {
public:
    
    bool isSafe(vector<string>& board, int row, int col, int n) {
        int temprow = row;
        int tempcol = col;
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        row = temprow;
        col = tempcol;
        
        while(row < n && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        
        row = temprow;
        col = tempcol;
        
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        return true;
    }
    void solve(vector<string>& board, vector<vector<string>>& ans, int col, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, ans, col + 1, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');
        
        for(auto &row : board) {
            row = s;
        }
        
        solve(board, ans, 0, n);
        return ans;
    }
};