class Solution {
    // static bool comp(vector<int> &a, vector<int>& b) {
    //     return a[1] < b[1];
    // }
public:
    int mod = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        
        int ans = 2;
        
        vector<int> curr = ranges[0];
        for(int i = 1; i < ranges.size(); i++) {
            if(ranges[i][0] <= curr[1]) {
                curr[0] = min(curr[0], ranges[i][0]);
                curr[1] = max(curr[1], ranges[i][1]);
            } else {
                ans = (ans * 2) % mod;
                curr = ranges[i];
            }
        }
        return ans;
    }
};