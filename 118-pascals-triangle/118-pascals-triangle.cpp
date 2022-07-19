class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        
        int r = 1;
        
        while(r < numRows) {
            vector<int> curr(r + 1);
            curr[0] = 1;
            curr[r] = 1;
            
            int i = 1;
            int pi = 0, pj = 1;
            
            while(pj < r) {
                curr[i++] = ans[r - 1][pi++] + ans[r - 1][pj++];
            }
            ans[r++] = curr;
        }
        return ans;
    }
};