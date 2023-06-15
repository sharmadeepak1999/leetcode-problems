class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(1000001);
        
        unordered_map<int, int> mp;
        
        for(auto &num:nums) mp[num]++;
        
        for(auto &it:mp) bucket[it.second].push_back(it.first);
        vector<int> ans;
        for(int i = 100000; i >= 0 && k > 0; i--) {
            if(bucket[i].size()) {
                for(int j = 0; j < bucket[i].size() && k > 0; j++) {
                    k--;
                    ans.push_back(bucket[i][j]);
                }
            }
        }
        return ans;
    }
};