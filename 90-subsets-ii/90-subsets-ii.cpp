class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& sub, int i) {
        ans.push_back(sub);
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j - 1]) continue;
            sub.push_back(nums[j]);
            helper(ans, nums, sub, j + 1);
            sub.pop_back();
        }
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        helper(ans, nums, sub, 0);
        return ans;
    }
};