class Solution {
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &visited, int i, int j, int m, int n) {
        visited[i][j] = 1;
        
        int offset[5] = { -1, 0, 1, 0, -1 };
        
        for(int k = 0; k < 4; k++) {
            int ni = i + offset[k];
            int nj = j + offset[k + 1];
            
            if(ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] == '0' || visited[ni][nj] == 1) continue;
            
            dfs(grid, visited, ni, nj, m, n);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int component = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    component++;
                    dfs(grid, visited, i, j, m, n);
                }
            }
        }
        return component;
    }
};