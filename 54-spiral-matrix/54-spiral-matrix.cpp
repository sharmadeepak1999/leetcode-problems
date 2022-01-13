class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> res;
        int c = row * col;
        int currRow = 0, currCol = col - 1, colStart = 0, colEnd = col - 1, rowStart = 1, rowEnd = row - 1;
        while(c >= 1) {
            for(int i = colStart; c >= 1 && i <= colEnd; i++) {
                res.push_back(matrix[currRow][i]);
                c--;
            }
            for(int j = rowStart; c >= 1 && j <= rowEnd; j++) {
                res.push_back(matrix[j][currCol]);
                c--;
            }
            colEnd--;
            for(int k = colEnd; c >= 1 && k >= colStart; k--) {
                res.push_back(matrix[row - currRow - 1][k]);
                c--;
            }
            rowEnd--;
            for(int l = rowEnd; c >= 1 && l >= rowStart; l--) {
                res.push_back(matrix[l][col - currCol - 1]);
                c--;
            }
            currRow++;
            currCol--;
            colStart++;
            rowStart++;
            cout << c;
        }
        return res;
    }
};