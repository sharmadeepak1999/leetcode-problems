class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int maxProf = INT_MIN;
        
        for(auto price : prices) {
            if(price < minBuy) minBuy = price;
            else maxProf = max(maxProf, price - minBuy);
        }
        return maxProf;
    }
};