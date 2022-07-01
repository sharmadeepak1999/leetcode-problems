class Solution {
public:
    /*
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
      */
    
    int maxProfit(vector<int>& prices) {
        int profit = 0; 
        int minPrice = prices[0];
        
        for(int i = 1; i < prices.size(); i++) {
            int price = prices[i];
            int currProfit = price - minPrice;
            if(currProfit > 0) {
                profit += currProfit;
                minPrice = price;
            } else {
                minPrice = min(minPrice, price);
            }
        }
        return profit;
    }
};