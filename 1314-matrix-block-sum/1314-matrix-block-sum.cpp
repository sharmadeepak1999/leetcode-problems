class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int mini = max(i - k, 1);
                int maxi = min(i + k, m);
                int minj = max(j - k, 1);
                int maxj = min(j + k, n);
                
                ans[i - 1][j - 1] = prefix[maxi][maxj] - prefix[maxi][minj - 1] - prefix[mini - 1][maxj] + prefix[mini - 1][minj - 1];
            }
        }
        return ans;
    }
};