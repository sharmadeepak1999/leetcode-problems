class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> front(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int nots = 0; nots < 2; nots++) {
                    if(buy) {
                        curr[buy][nots] = max(-prices[i] + front[0][nots], front[1][nots]);
                    } else curr[buy][nots] = max(prices[i] + front[1][nots + 1], front[0][nots]);
                }
            }
            front = curr;
        }
        return front[1][0];
    }
};