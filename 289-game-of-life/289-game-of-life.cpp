class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> newBoard = board;
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int nalive = 0;
                
                if(j < n - 1) {
                    if(board[i][j + 1] == 1) nalive++;
                    
                    if(i >= 1 && board[i - 1][j + 1] == 1) nalive++;
                    
                    if(i < m - 1 && board[i + 1][j + 1] == 1) nalive++;
                }
                
                if(j >= 1) {
                    if(board[i][j - 1] == 1) nalive++;
                    
                    if(i < m - 1 && board[i + 1][j - 1] == 1) nalive++;
                    if(i >= 1 && board[i - 1][j - 1] == 1) nalive++;
                    
                }
                
                if(i < m - 1 && board[i + 1][j] == 1) nalive++;
                if(i >= 1 && board[i - 1][j] == 1) nalive++;
                
                if(board[i][j] == 1) {
                    if(nalive < 2 || nalive > 3) newBoard[i][j] = 0;
                } else if(nalive == 3) newBoard[i][j] = 1;
                
            } 
        }
        board = newBoard;
    }
};