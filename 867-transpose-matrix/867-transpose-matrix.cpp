class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> transpose(column, vector<int>(row));
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }
        return transpose;
    }
};