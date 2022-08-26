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
        
        for(auto &n:nums) mp[n]++;
        
        map<int, vector<int>, greater<int>> mp2;
        
        for(auto &it:mp) mp2[it.second].push_back(it.first);
        
        vector<int> highFreqEle = mp2.begin() -> second;
        
        int minLen = INT_MAX;
        for(auto &e:highFreqEle) {
            int firstIndex = -1, secondIndex = -1; 
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == e) {
                    if(firstIndex == -1){
                        firstIndex = i;
                        secondIndex = i;
                    } else {
                        secondIndex = i;
                    }
                }
            }
            
            minLen = min(minLen, secondIndex - firstIndex + 1);
        }
        return minLen;
    }
};