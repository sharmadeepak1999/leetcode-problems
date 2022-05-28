class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // We can use 4 nested loops to get all the possibility, inorder to check for duplicated we can use set. and insert the quadraplets in sorted order.
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(long i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(long j = i + 1; j < nums.size(); j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                long lo = j + 1;
                long hi = nums.size() - 1; 
                
                while(lo < hi) {
                    long long sum = (long) (nums[i] + nums[j]) + nums[lo] + nums[hi];
                    if(sum == target) {
                       res.push_back({ nums[i], nums[j], nums[lo], nums[hi] });
                        while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++; 
                        hi--;
                    } else if(sum < target) {
                        lo++;
                    } else hi--;
                }
            }
        }
        return res;
    }
};

// [-2, -1, 0, 0, 1, 2]