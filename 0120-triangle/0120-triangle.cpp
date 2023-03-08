class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> front(triangle[m - 1].size(), INT_MAX);
        for(int i = 0; i < triangle[m - 1].size(); i++) {
            front[i] = triangle[m - 1][i];
        }
        
        for(int i = m - 2; i >= 0; i--) {
            vector<int> curr(triangle[m - 1].size(), INT_MAX);
            for(int j = 0; j < triangle[i].size(); j++) {
                int down = front[j];
                int diag = front[j + 1];
                curr[j] = triangle[i][j] + min(down, diag);
            }
            front = curr;
        }
        return front[0];
    }
};