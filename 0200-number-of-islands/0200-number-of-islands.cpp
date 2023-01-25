class Solution {
public:
    void helper(int i, int j, int m, int n, vector<vector<int>> &visited, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        
        q.push({i, j});
        visited[i][j] = 1;
        int offsets[] = {0, 1, 0, -1, 0};
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for(int a = 0; a < 4; a++) {
                int na = p.first + offsets[a];
                int nb = p.second + offsets[a + 1];

                if(na >= 0 && na < m && nb >= 0 && nb < n && grid[na][nb] == '1' && !visited[na][nb])                     {
                    visited[na][nb] = 1;
                    q.push({na, nb});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        int noi = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    helper(i, j, m, n, visited, grid);
                    noi++;
                }
            }
        }
        return noi;
    }
};