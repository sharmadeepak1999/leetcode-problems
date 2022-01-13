class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int> s;
        int row = matrix.size(), column = matrix[0].size();
        for(int i = 0; i < row; i++) {
            int minElement = INT_MAX;
            for(int j = 0; j < column; j++) {
                minElement = min(matrix[i][j], minElement);
            }
            s.insert(minElement);
        }
        vector<int> res;
        
        for(int i = 0; i < column; i++) {
            int maxElement = INT_MIN;
            for(int j = 0; j < row; j++) {
                maxElement = max(matrix[j][i], maxElement);
            }
            if(s.find(maxElement) != s.end()) {
                res.push_back(maxElement);        
            }
        }
        return res;
    }
};