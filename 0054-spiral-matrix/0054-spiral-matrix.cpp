class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int firstRow = 0, lastRow = m - 1, firstColumn = 0, lastColumn = n - 1;
        vector<int> ans;
        while(firstRow <= lastRow && firstColumn <= lastColumn) {
            for(int i = firstColumn; i <= lastColumn; i++) {
                ans.push_back(matrix[firstRow][i]);
            }
            firstRow++;
            for(int i = firstRow; i <= lastRow; i++) {
                ans.push_back(matrix[i][lastColumn]);
            }
            lastColumn--;
            if(lastRow < firstRow) break;
            for(int i = lastColumn; i >= firstColumn; i--) {
                ans.push_back(matrix[lastRow][i]);
            }
            lastRow--;
            if(lastColumn < firstColumn) break;
            for(int i = lastRow; i >= firstRow; i--) {
                ans.push_back(matrix[i][firstColumn]);
            }
            firstColumn++;
        }
        return ans;
    }
};