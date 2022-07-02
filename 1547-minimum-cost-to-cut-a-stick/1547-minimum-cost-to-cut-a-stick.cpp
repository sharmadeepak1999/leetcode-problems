class Solution {
public:
    /*
    int helper(vector<int>& cuts, int i, int j) {
        if(i > j) return 0;
        
        int mini = 1e9;
        
        for(int ind = i; ind <= j; ind++) {
            int cost = cuts[j + 1] - cuts[i - 1] + helper(cuts, i, ind - 1) + helper(cuts, ind + 1, j);
            mini = min(mini, cost);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        // inserting 0, and n at the first and the last position of the cuts array inorder to get the length of the stick or the cost at every partition step.
        
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        sort(cuts.begin(), cuts.end());
        return helper(cuts, 1, c);
    }
    */
    
    
    int helper(vector<int>& cuts,  vector<vector<int>> &dp, int i, int j) {
        if(i > j) return 0;
        
        int mini = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        for(int ind = i; ind <= j; ind++) {
            int cost = cuts[j + 1] - cuts[i - 1] + helper(cuts, dp, i, ind - 1) + helper(cuts, dp, ind + 1, j);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        // memoization
        
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        
        return helper(cuts, dp, 1, c);
    }
};