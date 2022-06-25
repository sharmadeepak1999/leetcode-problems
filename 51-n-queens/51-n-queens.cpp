class Solution {
public:
    /*
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
        // So we will prepare a board, using a vector of strings, and initialize the board to empty spaces '.', now we will call recursion to solve, in which we will go through each row of the current column, and check if it is possible to place a queen there, if yes then update the board, and call the recursion for the updated board, when the recursion returns remove the queen from this position. now the solve function would check if any queen is already present in the left up diagnoal or in the left down diagonal or in the left direction using loops if it is present in any such location then return false, else after every looop ends return true. we are only checking 3 direction because we are adding the queens from left to right so we wouldn't find a queen already placed in the right direction that could interefere with the current pos queen.
        
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');
        
        for(auto &row : board) {
            row = s;
        }
        
        solve(board, ans, 0, n);
        return ans;
    }
    */
    
    
    
    
    void solve(vector<string>& board, vector<vector<string>>& ans, int col, int n, vector<int> leftRow, vector<int> lowerDiagonal, vector<int> upperDiagonal) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(!leftRow[row] && !lowerDiagonal[row + col] && !upperDiagonal[n - 1 + col - row]) {
                board[row][col] = 'Q';
                leftRow[row]=1;
                lowerDiagonal[row + col]=1;
                upperDiagonal[n - 1 + col - row]=1;
                solve(board, ans, col + 1, n, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = '.';
                leftRow[row]=0;
                lowerDiagonal[row + col]=0;
                upperDiagonal[n - 1 + col - row]=0;
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
        
        vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
        
        solve(board, ans, 0, n, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};