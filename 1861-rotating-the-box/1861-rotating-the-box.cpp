class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        
        for(int i = 0; i < m; i++) {
            int stp = n;
            for(int j = n - 1; j >= 0; j--) {
                if(box[i][j] == '*') {
                    stp = j;
                    ans[j][m - i - 1] = '*';
                } else if(box[i][j] == '#') {
                    stp--;
                    ans[stp][m - i - 1] = '#';
                }
            }
        }
        return ans;
    }
};