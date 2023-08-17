class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = m * n - 1;
        
        while(l <= h) {
            int mid = (l + h) / 2;
            int c = mid % n;
            int r = mid / n;
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] < target) {
                l = mid + 1;
            } else if(matrix[r][c] > target) h = mid - 1;
        }
        return false;
    }
};