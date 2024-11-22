class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        int ans = 0;
        for(auto &row:matrix) {
            int first = row[0];
            
            string s = "";
            for(auto &e:row) {
                if(e == first) s += '1';
                else s += '0';
            }
            mp[s]++;
            ans = max(ans, mp[s]);
        }
        return ans;
    }
};