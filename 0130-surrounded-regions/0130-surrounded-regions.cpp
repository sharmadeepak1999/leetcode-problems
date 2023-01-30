class Solution {
public:
    void bfs(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            vector<int> offset = {-1, 0, 1, 0, -1};

            for(int k = 0; k < 4; k++) {
                int nrow = row + offset[k];
                int ncol = col + offset[k + 1];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            if(!visited[i][0] && board[i][0] == 'O') {
                bfs(board, visited, i, 0, m, n);
            }
            
            if(!visited[i][n - 1] && board[i][n - 1] == 'O') {
                bfs(board, visited, i, n - 1, m, n);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[0][i] && board[0][i] == 'O') {
                bfs(board, visited, 0, i, m, n);
            }
            
            if(!visited[m - 1][i] && board[m - 1][i] == 'O') {
                bfs(board, visited, m - 1, i, m, n);
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};