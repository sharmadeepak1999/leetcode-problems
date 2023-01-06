class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = -1;
        for(int i = 0; i < m; i++) {
            if(target <= matrix[i][n - 1]) {
                row = i;
                break;
            }
        }
        if(row == -1) return false;
        
        int lb = 0, ub = n - 1;
        
        while(lb <= ub) {
            int mid = (lb + ub) / 2;
            
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) lb = mid + 1;
            else ub = mid - 1;
        }
        return false;
    }
};