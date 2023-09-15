class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, pair<int, int>>> q;
        int freshCount = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({ 0, { i, j }});
                } else if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        int time = 0;
        while(!q.empty()) {
            int i = q.front().second.first;
            int j = q.front().second.second;
            int t = q.front().first;
            q.pop();
            time = max(time, t);
            
            int offset[5] = {-1, 0, 1, 0, -1};
            
            for(int k = 0; k < 4; k++) {
                int ni = i + offset[k];
                int nj = j + offset[k + 1];
                
                if(ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == 0 || grid[ni][nj] == 2) continue;
                grid[ni][nj] = 2;
                freshCount--;
                q.push({ t + 1, { ni, nj }});
            }
        }
        if(freshCount > 0) return -1;
        return time;
        
    }
};