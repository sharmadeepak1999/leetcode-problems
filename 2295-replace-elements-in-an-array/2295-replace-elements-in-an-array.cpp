class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
        
        for(auto &o:operations) {
            mp[o[1]] = mp[o[0]];
            mp.erase(o[0]);
        }
        
        vector<int> ans(nums.size());
        
        for(auto &it:mp) {
            ans[it.second] = it.first;
        }
        return ans;
    }
};