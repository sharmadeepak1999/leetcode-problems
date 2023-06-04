class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false, firstColZero = false;
        
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) firstRowZero = true;
                    if(j == 0) firstColZero = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(firstRowZero) {
            for(int i = 0; i < n; i++) matrix[0][i] = 0;
        }
        if(firstColZero) {
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};