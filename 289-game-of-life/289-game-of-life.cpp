class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        // Brute force, we will visit each element in the matrix or board, one by one, and count the alive neighbours while making sure to be in the boundary of matrix, after that we will update the state of current element according to the given constraints.
        
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int nalive = 0;
                
                if(j < n - 1) {
                    if(board[i][j + 1] == 1 || board[i][j + 1] == -1) nalive++;
                    
                    if(i >= 1 && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == -1)) nalive++;
                    
                    if(i < m - 1 && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == -1)) nalive++;
                }
                
                if(j >= 1) {
                    if(board[i][j - 1] == 1 || board[i][j - 1] == -1) nalive++;
                    
                    if(i < m - 1 && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == -1)) nalive++;
                    if(i >= 1 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == -1)) nalive++;
                    
                }
                
                if(i < m - 1 && (board[i + 1][j] == 1 || board[i + 1][j] == -1)) nalive++;
                if(i >= 1 && (board[i - 1][j] == 1 || board[i - 1][j] == -1)) nalive++;
                
                if(board[i][j] == 1 || board[i][j] == -1) {
                    if(nalive < 2 || nalive > 3) board[i][j] = -1;
                } else if(nalive == 3) board[i][j] = -2;
            } 
        }
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == -2) board[i][j] = 1;
            } 
        }
    }
};