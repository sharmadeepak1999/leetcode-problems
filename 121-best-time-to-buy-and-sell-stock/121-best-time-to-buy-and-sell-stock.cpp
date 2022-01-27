class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), maxProfit = INT_MIN, minValue = prices[0];
        for(int i = 1; i < size; i++) {
            maxProfit = max(maxProfit, prices[i] - minValue);
            minValue = min(minValue, prices[i]);
        }
        return maxProfit < 0 ? 0 : maxProfit;
    }
};