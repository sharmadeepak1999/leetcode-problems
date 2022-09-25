class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        
        while(i < m) {
            if(target <= matrix[i][n - 1]) break;
            i++;
        }
        if(i >= m) return false;
        int l = 0, h = n - 1;
        
        while(l <= h) {
            int mid = (l + h) / 2;
            
            if(matrix[i][mid] == target) return true;
            else if(matrix[i][mid] < target) l = mid + 1;
            else h = mid - 1;
        }
        return false;
    }
};