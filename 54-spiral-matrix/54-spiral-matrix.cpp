class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> res;
        int colStart = 0, colEnd = col - 1, rowStart = 0, rowEnd = row - 1;
        while(rowStart <= rowEnd && colStart <= colEnd) {
            for(int i = colStart; i <= colEnd; i++) {
                res.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            for(int j = rowStart; j <= rowEnd; j++) {
                res.push_back(matrix[j][colEnd]);
            }
            colEnd--;
            if(rowStart <= rowEnd) {
                for(int k = colEnd; k >= colStart; k--) {
                    res.push_back(matrix[rowEnd][k]);
                }
                rowEnd--;   
            }
            if(colStart <= colEnd) {
                for(int l = rowEnd; l >= rowStart; l--) {
                    res.push_back(matrix[l][colStart]);
                }
                colStart++;
            }
        }
        return res;
    }
};