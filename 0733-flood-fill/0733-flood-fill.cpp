class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        visited[sr][sc] = 1;
        
        int original = image[sr][sc];
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            image[row][col] = color;
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + offset[i];
                int ncol = col + offset[i + 1];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && image[nrow][ncol] == original) {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return image;
    }
};