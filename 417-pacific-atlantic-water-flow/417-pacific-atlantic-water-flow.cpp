class Solution {
public:
    void traverse(vector<vector<int>> &heights, int m, int n, int i, int j, int prev, bool &inPacific, bool &inAtlantic) {
        if(inPacific && inAtlantic) return;
        if(i < 0 || j < 0) {
            inPacific = true;
            return;
        }
        if(i >= m || j >= n) {
            inAtlantic = true;
            return;
        }
        if(prev < heights[i][j]) return;
        prev = heights[i][j];
        heights[i][j] = INT_MAX;
        traverse(heights, m, n, i + 1, j, prev, inPacific, inAtlantic);
        traverse(heights, m, n, i, j + 1, prev, inPacific, inAtlantic);
        traverse(heights, m, n, i - 1, j, prev, inPacific, inAtlantic);
        traverse(heights, m, n, i, j - 1, prev, inPacific, inAtlantic);
        heights[i][j] = prev;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        
        int m = heights.size();
        int n = heights[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int prev = INT_MAX;
                bool isPacific = false, isAtlantic = false;
                traverse(heights, m, n, i, j, prev, isPacific, isAtlantic);
                if(isPacific && isAtlantic) ans.push_back({i, j});
            }
        }
        return ans;
    }
};