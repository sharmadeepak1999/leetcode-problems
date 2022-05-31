class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int cols = 0, cole = matrix[0].size() - 1, rowe = matrix.size() - 1, rows = 0;
        vector<int> ans;
        while(cols <= cole && rows <= rowe) {
            for(int i = cols; i <= cole; i++) {
                ans.push_back(matrix[rows][i]);
                
            }
            rows++;

            for(int i = rows; i <= rowe; i++) {
                ans.push_back(matrix[i][cole]);
            }

            cole--;
            if(rows <= rowe) {
                for(int i = cole; i >= cols; i--) {
                    ans.push_back(matrix[rowe][i]);
                }
                rowe--;   
            }
            
            if(cols <= cole) {
                for(int i = rowe; i >= rows; i--) {
                    ans.push_back(matrix[i][cols]);
                }
                cols++;
            }
        }
        
        return ans;
    }
};