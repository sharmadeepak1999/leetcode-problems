class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        
        int count = 0;
        
        for(int i = 0; i < m; i++) {
            int lo = 0, hi = n - 1, mid;
            int firstNegIndex = n;
            while(lo <= hi) {
                mid = (lo + hi) / 2;
                if(grid[i][mid] < 0) {
                    firstNegIndex = mid;
                    hi = mid - 1;
                } else lo = mid + 1;
            }
            count += n - firstNegIndex;
        }
        return count;
    }
};