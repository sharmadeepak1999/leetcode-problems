class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                } else if(grid[i][j] == 1) freshCount++;
            }
        }
        int minTime = 0;
        while(!q.empty()) {
            vector<int> tuple = q.front();
            q.pop();
            
            int i = tuple[0];
            int j = tuple[1];
            int time = tuple[2];
            minTime = max(minTime, time);
            int offset[5] = {-1, 0, 1, 0, -1};
            
            for(int k = 0; k < 4; k++) {
                int ni = i + offset[k];
                int nj = j + offset[k + 1];
                
                if(ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] == 2 || grid[ni][nj] == 0) continue;
                freshCount--;
                grid[ni][nj] = 2;
                q.push({ ni, nj, time + 1 });
            }
        }
        
        if(freshCount > 0) return -1;
        return minTime;
    }
};