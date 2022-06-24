class Solution {
public:
    void helper(vector<int>& nums, set<vector<int>>& s, int i, int n) {
        if(i == n) {
            if(s.find(nums) == s.end()) {
                s.insert(nums);
            }
            return;
        }
        
        for(int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            helper(nums, s, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        helper(nums, s, 0, nums.size());
        vector<vector<int>> v;
        for(auto &it : s) {
            v.push_back(it);
        }
        return v;
    }
};