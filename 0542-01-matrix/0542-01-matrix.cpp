class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j, 0 });
                }
            }
        }
        
        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int d = q.front()[2];
            
            q.pop();
            int offset[5] = {-1, 0, 1, 0, -1};
            
            for(int k = 0; k < 4; k++) {
                int ni = i + offset[k];
                int nj = j + offset[k + 1];
                
                if(ni < 0 || nj < 0 || ni >= m || nj >= n || mat[ni][nj] == 0) continue;
                
                if(d + 1 < dist[ni][nj]) {
                    dist[ni][nj] = d + 1;
                    q.push({ ni, nj, d + 1 });
                }
            }
        }
        return dist;
    }
};