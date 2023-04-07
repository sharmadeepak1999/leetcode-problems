class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>> &visited, vector<vector<int>>& grid) {
        visited[i][j] = 1;
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        for(int k = 0; k < 4; k++) {
            int nrow = i + offset[k];
            int ncol = j + offset[k+1];
            
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, m, n, visited, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            if(!visited[i][0] && grid[i][0] == 1) dfs(i, 0, m, n, visited, grid);
            if(!visited[i][n - 1] && grid[i][n - 1] == 1) dfs(i, n - 1, m, n, visited, grid);
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[0][i] && grid[0][i] == 1) dfs(0, i, m, n, visited, grid);
            if(!visited[m - 1][i] && grid[m - 1][i] == 1) dfs(m - 1, i, m, n, visited, grid);
        }
        
        int count = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};