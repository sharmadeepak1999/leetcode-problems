class Solution {
public:
    bool isPossible(vector<vector<int>> &board, int row, int col, int n) {
        for(int i = row - 1; i >= 0; i--) {
            if(board[i][col] == 1) return false;
        }
        for(int i = col - 1; i >= 0; i--) {
            if(board[row][i] == 1) return false;
        }
        
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 1) return false;
        }
        
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 1) return false;
        }
        return true;
    }
    
    void helper(vector<vector<int>> &board, vector<vector<string>> &solutions, int row, int n) {
        if(row == n) {
            vector<string> sol;
            for(int i = 0; i < n; i++) {
                string r = "";
                for(int j = 0; j < n; j++) {
                    if(board[i][j] == 1) r += 'Q';
                    else r += '.';
                }
                sol.push_back(r);
            }
            solutions.push_back(sol);
            return;
        }
        
        
        for(int i = 0; i < n; i++) {
            if(isPossible(board, row, i, n)) {
                board[row][i] = 1;
                helper(board, solutions, row + 1, n);
                board[row][i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(10, vector<int>(10, 0));
        vector<vector<string>> solutions;
        helper(board, solutions, 0, n);
        return solutions;
    }
};