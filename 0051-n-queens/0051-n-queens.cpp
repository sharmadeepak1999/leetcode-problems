class Solution {
    bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
        for(int i = row - 1; i >= 0; i--) {
            if(board[i][col] == 1) return false;
        }
        
        int i = row - 1, j = col - 1;
        while(i >= 0 && j >= 0) {
            if(board[i][j] == 1) return false;
            i--;
            j--;
        }
        i = row - 1, j = col + 1;
        while(i >= 0 && j < n) {
            if(board[i][j] == 1) return false;
            i--;
            j++;
        }
        return true;
    }
    void helper(vector<vector<int>> &board, vector<vector<string>> &ans, int row, int n) {
        if(row == n) {
            vector<string> res;
            
            for(int i = 0; i < n; i++) {
                string s;
                for(int j = 0; j < n; j++) {
                    if(board[i][j] == 1) s.push_back('Q');
                    else s.push_back('.');
                }
                res.push_back(s);
            }
            
            ans.push_back(res);
        }
        
        for(int col = 0; col < n; col++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 1;
                helper(board, ans, row + 1, n);
                board[row][col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        
        helper(board, ans, 0, n);
        return ans;
    }
};