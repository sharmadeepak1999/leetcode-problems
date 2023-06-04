class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        
        int buy = -1;
        
        for(auto &price:prices) {
            if(buy == -1) buy = price;
            
            if(price < buy) buy = price;
            maxi = max(maxi, price - buy);
        }
        return maxi;
    }
};