class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size() == 1) return 0;
        sort(stockPrices.begin(), stockPrices.end());
    
        long long prevY = (stockPrices[1][1] - stockPrices[0][1]);
        long long prevX = (stockPrices[1][0] - stockPrices[0][0]);
        
        int l = 1;
        
        for(int i = 2; i < stockPrices.size(); i++) {
            long long currY = (stockPrices[i][1] - stockPrices[i - 1][1]);
            long long currX = (stockPrices[i][0] - stockPrices[i - 1][0]);
            if(prevY * currX != prevX * currY) {
                l++;
                prevY = currY;
                prevX = currX;
            }
        }
        return l;
    }
};