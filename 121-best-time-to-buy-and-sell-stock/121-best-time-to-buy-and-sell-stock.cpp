class Solution {
public:
    /*
    int maxProfit(vector<int>& prices) {
        // check for every pair in the array using two loops and maintain a max variable, check if the curr pair is max.
        
        // Start from the first day price, compare it with second day price if it is greater, then calculate the profit and check if it is max profit, else initialize the buying price as current price.
        int mp = 0;
        int b = prices[0];
        for(auto p : prices) {
            int curr = p - b;
            if(curr < 0) {
                b = p;
            } else {
                mp = max(mp, curr);
            }
        }
        return mp;
    }
    */
    
    
    int maxProfit(vector<int>& prices) {
        // If we sell at any index, we will have to try to buy at the minimum cost before that index, so we will start from the second element, and calculate the profit taking the first element as the minPrice, and update the profit as required, as well as update the minPrice according to the current price
        int minPrice = prices[0], profit = 0;
        
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            int currProfit = prices[i] - minPrice;
            profit = max(profit, currProfit);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};