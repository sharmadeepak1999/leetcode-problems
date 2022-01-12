class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, row = mat.size();
        int column = row;
        for(int i = 0; i < row; i++) {
            sum += mat[i][i];
            sum += mat[i][column - i - 1];
        }
        if(row % 2 != 0) {
            sum -= mat[row / 2][column / 2];
        }
        return sum;
    }
};