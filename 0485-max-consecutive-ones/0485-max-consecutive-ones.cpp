class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        
        for(auto &num:nums) {
            if(num == 1) {
                count++;
                maxi = max(maxi, count);
            } else count = 0;
        }
        return maxi;
    }
};