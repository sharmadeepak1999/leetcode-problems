class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<int> prev(n, -1);
        for(int i = 0; i < m; i++) {
            vector<int> curr(n, -1);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) curr[j] = 1;
                else {
                    int left = 0, up = 0;
                    
                    if(i > 0 && obstacleGrid[i - 1][j] != 1) up = prev[j];
                    if(j > 0 && obstacleGrid[i][j - 1] != 1) left = curr[j - 1];
                    curr[j] = left + up;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};