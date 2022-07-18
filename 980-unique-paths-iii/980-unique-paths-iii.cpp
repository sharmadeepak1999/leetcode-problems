class Solution {
public:
    int helper(vector<vector<int>>& grid, int m, int n, int i, int j, int c) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == -1 || grid[i][j] == -2) return 0;
        
        if(grid[i][j] == 2) {
            if(c == 1) return 1;
            return 0;
        }
        
        grid[i][j] = -1;
        int left = helper(grid, m, n, i, j + 1, c - 1);
        int right = helper(grid, m, n, i, j - 1, c - 1);
        int up = helper(grid, m, n, i - 1, j, c - 1);
        int down = helper(grid, m, n, i + 1, j, c - 1);
        grid[i][j] = 0;

        return left + right + up + down;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int si, sj;
        int m = grid.size(), n = grid[0].size();
        int obs = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                } else if(grid[i][j] == -1) obs++;
            }
        }
        return helper(grid, m, n, si, sj, m * n - obs);   
    }
};