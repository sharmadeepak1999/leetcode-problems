class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        /*
        vector<int> rows(m, 0), cols(n, 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                } 
            }
        }
        
        for(int i = 0; i < m; i++) {
            if(rows[i]) {
                for(int j = 0; j < n; j++) matrix[i][j] = 0;
            }
        }
        
        for(int j = 0; j < n; j++) {
            if(cols[j]) {
                for(int i = 0; i < m; i++) matrix[i][j] = 0;
            }
        }
        
        */
        
        bool firstRowZero = false, firstColZero = false;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) firstRowZero = true;
                    if(j == 0) firstColZero = true;
                    
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        if(firstRowZero) {
            for(int j = 0; j < n; j++) matrix[0][j] = 0;
        }
        
        if(firstColZero) {
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};