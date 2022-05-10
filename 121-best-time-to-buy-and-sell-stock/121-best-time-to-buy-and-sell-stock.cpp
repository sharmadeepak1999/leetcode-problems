class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
};