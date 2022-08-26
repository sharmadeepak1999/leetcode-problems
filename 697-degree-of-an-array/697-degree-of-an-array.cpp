class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        /*
        int maxFreq = 0;
        int minLen = INT_MAX;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int freq = 0, lastIndex = i;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] == nums[i]) {
                    freq++;
                    lastIndex = j;
                }
            }
            
            if(freq == maxFreq) {
                minLen = min(minLen, lastIndex - i + 1);
            } else if(freq > maxFreq) {
                maxFreq = freq;
                minLen = lastIndex - i + 1;
            } 
        }
        return minLen;
        */
        
        unordered_map<int, int> mp;
        unordered_map<int, pair<int, int>> mp2;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp2.find(nums[i]) == mp2.end()) {
                mp2[nums[i]].first = i, mp2[nums[i]].second = i;
            } else mp2[nums[i]].second = i;
        }
        
        int highFreq = 0;
        for(auto &it:mp) 
            if(it.second > highFreq) highFreq = it.second;
        int minLen = INT_MAX;
        for(auto &it:mp) {
            if(it.second == highFreq) {
                minLen = min(minLen, mp2[it.first].second - mp2[it.first].first + 1);
            }
        }
        return minLen;
    }
};