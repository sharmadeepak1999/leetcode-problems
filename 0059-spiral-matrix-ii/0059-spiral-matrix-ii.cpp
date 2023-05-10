class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        int firstRow = 0, lastRow = n - 1, firstColumn = 0, lastColumn = n - 1;
        int c = 1;
        while(firstRow <= lastRow && firstColumn <= lastColumn) {
            for(int i = firstColumn; i <= lastColumn; i++) ans[firstRow][i] = c++;
            firstRow++;
            if(lastColumn < firstColumn) break;
            for(int i = firstRow; i <= lastRow; i++) ans[i][lastColumn] = c++;
            lastColumn--;
            if(lastRow < firstRow) break;
            for(int i = lastColumn; i >= firstColumn; i--) ans[lastRow][i] = c++;
            lastRow--;
            for(int i = lastRow; i >= firstRow; i--) ans[i][firstColumn] = c++;
            firstColumn++;
        }
        return ans;
    }
};