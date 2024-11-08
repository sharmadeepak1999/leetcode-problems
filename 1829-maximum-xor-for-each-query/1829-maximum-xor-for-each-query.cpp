class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xori = 0;
        
        for(auto &num:nums) xori ^= num;
        
        int maxi = pow(2, maximumBit) - 1;
        
        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans.push_back(maxi ^ xori);
            xori ^= nums[i];
        }
        return ans;
    }
};
