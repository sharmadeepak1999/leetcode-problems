class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(32, 0);
        
        for(auto num:candidates) {
            for(int i = 0; i < 32; i++) {
                bits[31 - i] += (num & (1 << i)) != 0;
            }
        }
        
        int ans = *max_element(bits.begin(), bits.end());
        return ans;
    }
};