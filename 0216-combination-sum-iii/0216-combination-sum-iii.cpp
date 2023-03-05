class Solution {
public:
    void helper(int nums[], vector<vector<int>> &ans, vector<int> sub, int k, int target, int i) {
        if(i == 9) {
            if(target == 0 && k == 0) {
                ans.push_back(sub);
            }
            return;
        }
        sub.push_back(nums[i]);
        helper(nums, ans, sub, k - 1, target - nums[i], i + 1);
        sub.pop_back();
        helper(nums, ans, sub, k, target, i + 1);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> sub;
        helper(nums, ans, sub, k, n, 0);
        return ans;
    }
};