class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        vector<int> front(n, 1e9);
        for(int i = 0; i < n; i++) {
            front[i] = matrix[n - 1][i];
        }
        for(int i = n - 2; i >= 0; i--) {
            vector<int> curr(n, 1e9);
            for(int j = 0; j < n; j++) {
                int ldiag = 1e9, rdiag = 1e9, down = 1e9;
                
                if(j > 0) ldiag = front[j - 1];
                down = front[j];
                if(j < n - 1) rdiag = front[j + 1];
                curr[j] = matrix[i][j] + min(min(ldiag, rdiag), down);
            }
            front = curr;
        }
        for(int i = 0; i < n; i++) {
            mini = min(mini, front[i]);
        }
        return mini;
    }
};