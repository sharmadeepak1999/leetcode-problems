class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        // Using heap
        unordered_map<int, int> freq;
        
        for(auto &num:nums) freq[num]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto &it:freq) {
            pq.push({ it.second, it.first });
        }
        
        vector<int> ans;
        
        for(int i = 1; i <= k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        */
        
        // bucket sort
        
        unordered_map<int, int> freq;
        
        for(auto &num:nums) freq[num]++;
        
        vector<vector<int>> bucket(nums.size() + 1);
        
        
        for(auto &it:freq) {
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;
        
        int i = bucket.size() - 1;
        
        while(i >= 0) {
            while(i >= 0 && bucket[i].size() == 0) i--;
            if(i >= 0) {
                for(int j = 0; j < bucket[i].size(); j++) {
                    k--;
                    ans.push_back(bucket[i][j]);
                    if(k == 0) break;
                }
            }
            if(k == 0) break;
            i--;
        }
        return ans;
    }
};