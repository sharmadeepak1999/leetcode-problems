class Solution {
    int helper(vector<pair<int, int>> &v, int i, int j, vector<vector<int>> &dp) {
        if(i == v.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick = 0;
        if(j - 1 == -1 || v[i].second >= v[j - 1].second) pick = v[i].second + helper(v, i + 1, i + 1, dp);
        int notpick = helper(v, i + 1, j, dp);
        return dp[i][j] = max(pick, notpick);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> v;
        int n = ages.size();
        for(int i = 0; i < n; i++) {
            v.push_back({ ages[i], scores[i] });
        }
        sort(v.begin(), v.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(v, 0, 0, dp);
    }
};