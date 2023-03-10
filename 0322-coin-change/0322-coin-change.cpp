class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 1e9);
        prev[0] = 0;
        for(int ai = 0; ai <= amount; ai++) {
            if(ai % coins[0] == 0) prev[ai] = ai / coins[0];
        }
        for(int i = 1; i < n; i++) {
            vector<int> curr(amount + 1, 1e9);
            curr[0] = 0;
            for(int ai = 0; ai <= amount; ai++) {
                int nottake = prev[ai];
                int take = 1e9;
                if(coins[i] <= ai) take = 1 + curr[ai - coins[i]];
                curr[ai] = min(nottake, take);
            }
            prev = curr;
        }
        int res = prev[amount];
        return res == 1e9 ? -1 : res;
    }
};