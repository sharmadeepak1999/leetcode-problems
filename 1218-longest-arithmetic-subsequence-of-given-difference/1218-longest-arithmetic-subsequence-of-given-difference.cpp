class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 1;
        for(int i = 0; i < arr.size(); i++) {
            if(dp.find(arr[i] - difference) != dp.end()) {
                dp[arr[i]] = dp[arr[i] - difference] + 1;
            } else dp[arr[i]] = 1;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};