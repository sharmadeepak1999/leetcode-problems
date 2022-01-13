class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> minRow, maxCol;
        int row = matrix.size(), column = matrix[0].size();
        for(int i = 0; i < row; i++) {
            int minElement = INT_MAX;
            for(int j = 0; j < column; j++) {
                minElement = min(matrix[i][j], minElement);
            }
            minRow.push_back(minElement);
        }
        
        for(int i = 0; i < column; i++) {
            int maxElement = INT_MIN;
            for(int j = 0; j < row; j++) {
                maxElement = max(matrix[j][i], maxElement);
            }
            maxCol.push_back(maxElement);
        }
        
        vector<int> res;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(minRow[i] == maxCol[j]) {
                    res.push_back(minRow[i]);
                }
            }
        }
        return res;
    }
};