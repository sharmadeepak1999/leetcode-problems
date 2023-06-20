class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, INT_MAX)));
        for(int i = 0; i <= n; i++) {
            dp[i][n][0] = 0;
        }
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                for(int p = 1; p <= k; p++) {
                    int cost = dp[j + 1][j + 1][p - 1];
                    if(cost != INT_MAX) {
                        for(int t = i; t <= j; t++) {
                            cost += abs(houses[(i + j) / 2] - houses[t]);
                        }
                    }
                    dp[i][j][p] = min(cost, dp[i][j + 1][p]);
                }
            }
        }
        return dp[0][0][k];
    }
};