class Solution {
    bool isSafe(vector<vector<int>> &board, int i, int j, int n) {
        for(int k = i - 1; k >= 0; k--) {
            if(board[k][j] == 1) return false;
        }
        int p = i - 1, q = j - 1;
        
        while(p >= 0 && q >= 0) {
            if(board[p][q] == 1) return false;
            p--;
            q--;
        }
        p = i - 1, q = j + 1;
        
        while(p >= 0 && q < n) {
            if(board[p][q] == 1) return false;
            p--;
            q++;
        }
        return true;
    }
    void helper(vector<vector<string>> &ans, vector<vector<int>> &board, int row, int n) {
        if(row == n) {
            vector<string> temp;
            
            for(int i = 0; i < n; i++) {
                string s;
                for(int j = 0; j < n; j++) {
                    if(board[i][j] == 1) s += 'Q';
                    else s += '.';
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        
        for(int j = 0; j < n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 1;
                helper(ans, board, row + 1, n);
                board[row][j] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        
        helper(ans, board, 0, n);
        return ans;
    }
};