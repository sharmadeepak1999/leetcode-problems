class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> front(2, 0), curr(2, 0);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy == 1) {
                    curr[buy] = max(-prices[i] + front[0], front[1]);
                } else curr[buy] = max(prices[i] - fee + front[1], front[0]);
            }
            front = curr;
        }
        return front[1];
    }
};