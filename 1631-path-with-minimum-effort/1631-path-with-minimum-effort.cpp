class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int m = heights.size(), n = heights[0].size();        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        pq.push({0, { 0, 0 }});
        dist[0][0] = 0;
        while(!pq.empty()) {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
        
            pq.pop();
            if(row == m - 1 && col == n - 1) return diff;
            int offset[5] = {-1, 0, 1, 0, -1};
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + offset[i];
                int ncol = col + offset[i + 1];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    int newdiff = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    
                    if(newdiff < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newdiff;
                        pq.push({newdiff, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};