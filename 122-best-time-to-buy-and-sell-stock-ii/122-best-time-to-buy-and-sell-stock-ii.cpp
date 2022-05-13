class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        int b = prices[0];
        for(auto &p : prices) {
            if(p > b) {
                profit += p - b;
            }
            b = p;
        }
        return profit;
      }
};