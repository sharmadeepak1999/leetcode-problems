class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, pair<int, int>> mp;
        
        sort(nums.begin(), nums.end());
        
        for(auto &num:nums) {
            if(mp.find(num % space) == mp.end()) mp[num % space] = { num, 1 };
            else mp[num % space].second++;
        }
        int minNum = INT_MAX;
        int maxTarget = 0;
        for(auto &it:mp) {
            if(it.second.second > maxTarget || (it.second.second == maxTarget && it.second.first < minNum)) {
                maxTarget = it.second.second;
                minNum = it.second.first;
            }
        }
        return minNum;
    }
};