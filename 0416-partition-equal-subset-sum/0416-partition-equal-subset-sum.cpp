class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int osum = accumulate(nums.begin(), nums.end(), 0);
        if(osum % 2 == 1) return false;
        int target = osum / 2;
        vector<int> prev(target + 1, 0);
        prev[0] = true;
        for(int i = 1; i < n; i++) {
            vector<int> curr(target + 1, 0);
            curr[0] = true;
            for(int j = 1; j <= osum / 2; j++) {
                int nottake = prev[j];
                int take = 0;
                if(j >= nums[i]) take = prev[j - nums[i]];
                curr[j] = take or nottake;
            }
            prev = curr;
        }
        return prev[osum / 2];
    }
};