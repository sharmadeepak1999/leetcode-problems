class Solution {
public:
    // int helper(vector<int>& prices, int s, int e) {
    //     if(s >= e) {
    //         return 0;
    //     }
    //     int profit = 0;
    //     for(int i = s; i < e; i++) {
    //         for(int j = i + 1; j <= e; j++) {
    //             if(prices[j] > prices[i]) {
    //                 int currProfit = prices[j] - prices[i] + helper(prices, s, i - 1) + helper(prices, j + 1, e);
    //                 profit = max(profit, currProfit);   
    //             }
    //         }
    //     }
    //     return profit;
    // }
    
    int maxProfit(vector<int>& prices) {
        int profit = 0, size = prices.size();
        for(int i = 1; i < size; i++) {
            if(prices[i] > prices[i - 1]){
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};