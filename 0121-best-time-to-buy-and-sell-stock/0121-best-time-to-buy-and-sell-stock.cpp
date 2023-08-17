class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int i = 0;
        for(int j = 1; j < prices.size(); j++) {
            if(prices[j] > prices[i]) maxi = max(maxi, prices[j] - prices[i]);
            else i = j;
        }
        return maxi;
    }
};