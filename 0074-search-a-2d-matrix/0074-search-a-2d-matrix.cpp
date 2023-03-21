class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; i++) {
            if(matrix[i][n - 1] >= target) {
                int l = 0, h = n - 1;
                
                while(l <= h) {
                    int mid = (l + h) / 2;
                    
                    if(matrix[i][mid] == target) return true;
                    else if(matrix[i][mid] < target) l = mid + 1;
                    else h = mid - 1;
                }
            }
        }
        return false;
    }
};