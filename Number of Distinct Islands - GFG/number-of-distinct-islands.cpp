//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        set<vector<pair<int, int>>> s;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    pair<int, int> base;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    base = {i, j};
                    
                    while(!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        
                        q.pop();
                        
                        shape.push_back({ row - base.first, col - base.second });
                        
                        vector<int> offset = {-1, 0, 1, 0, -1};
                        
                        for(int k = 0; k < 4; k++) {
                            int nrow = row + offset[k];
                            int ncol = col + offset[k + 1];
                            
                            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                                q.push({nrow, ncol});
                                visited[nrow][ncol] = 1;
                                
                            }
                        }
                    }
                    
                    s.insert(shape);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends