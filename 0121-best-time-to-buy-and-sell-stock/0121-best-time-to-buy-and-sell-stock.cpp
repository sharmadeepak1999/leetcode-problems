class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mprofit = 0;
        int buy = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < buy) buy = prices[i];
            mprofit = max(mprofit, prices[i] - buy);
        }
        return mprofit;
    }
};