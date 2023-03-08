class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> prev(n);
        for(int i = 0; i < m; i++) {
            vector<int> curr(n);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) curr[j] = grid[i][j];
                else {
                    int left = 1e9, up = 1e9;
                    if(i > 0) up = grid[i][j] + prev[j];
                    if(j > 0) left = grid[i][j] + curr[j - 1];
                    curr[j] = min(left, up);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};