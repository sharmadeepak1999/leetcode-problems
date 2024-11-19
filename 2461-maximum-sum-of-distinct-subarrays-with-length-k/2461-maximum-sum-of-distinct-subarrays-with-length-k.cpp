class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        int s = 0;
        
        long long winsum = 0, maxi = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i - s + 1 <= k) {
                winsum += nums[i];
                mp[nums[i]]++;
                if(mp[nums[i]] > 1) {
                    st.insert(nums[i]);
                } 
            } else {
                if(st.size() == 0)
                    maxi = max(maxi, winsum);
                mp[nums[s]]--;
                mp[nums[i]]++;
                winsum -= nums[s];
                winsum += nums[i];
                if(mp[nums[s]] <= 1) st.erase(nums[s]);
                if(mp[nums[i]] > 1) st.insert(nums[i]);
                s++;
            }
        }
        
        if(st.size() == 0)
            maxi = max(maxi, winsum);
        return maxi;
    }
};