//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int row, int col1, int col2, int m, int n) {
        if(col1 < 0 || col1 > n || col2 < 0 || col2 > n) return 0;
        if(row == m) {
            if(col1 == col2) return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }
        if(dp[row][col1][col2] != 0) return dp[row][col1][col2];
        int offset[] = {-1, 0, 1};
        int maxi = INT_MIN;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(col1 == col2) {
                    maxi = max(maxi, grid[row][col1] + helper(grid, dp, row + 1, col1 + offset[i], col2 + offset[j], m, n));
                } else {
                    maxi = max(maxi, grid[row][col1] + grid[row][col2] + helper(grid, dp, row + 1, col1 + offset[i], col2 + offset[j], m, n));
                }
            }
        }
        return dp[row][col1][col2] = maxi;
    }
    int solve(int m, int n, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        return helper(grid, dp, 0, 0, n - 1, m - 1, n - 1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends