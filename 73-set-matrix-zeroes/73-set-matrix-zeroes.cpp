class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < col; k++) {
                        ans[i][k] = 0;
                    }
                    
                    for(int l = 0; l < row; l++) {
                        ans[l][j] = 0;
                    }
                } else if(ans[i][j] != 0) {
                    ans[i][j] = matrix[i][j];
                }
            }
        }
        matrix = ans;
    }
};