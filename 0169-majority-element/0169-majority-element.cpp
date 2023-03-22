class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int k = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != ans) {
                k--;
                if(k == 0) {
                    ans = nums[i];
                    k = 1;
                }
            } else k++;
        }
        return ans;
    }
};