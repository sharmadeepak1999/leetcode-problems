class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    /*
    // If the values in the array is greater than some defined number than we can take a value less than that number and        use it as a marker. This approach won't work in this problem cause we have range including both positive and negative       values.
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    for(int k = 0; k < matrix.size(); k++) {
                        if(matrix[k][j] != 0)
                            matrix[k][j] = -1;
                    }
                    
                    for(int l = 0; l < matrix[0].size(); l++) {
                        if(matrix[i][l] != 0)
                            matrix[i][l] = -1;
                    }
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    */
        
        
        
        
    /*
        
    // We can create two seperate set that represent the rows and column of the matrix, when we find a zero in the matrix,      we set the row and column of it in the set as zero. After traversing through the whole matrix, we traverse again this       time we check if the current row no. or col. no in the set is zero then we set that cell as zero.
        
        vector<int> rows(matrix.size(), -1), cols(matrix[0].size(), -1);
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(rows[i] == 0 || cols[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    */
        
    // We can also take the first row and col of matrix as the marker array. we need to give special care to the a[0][0] cell as it comes both in the row and col marker array. so we maintain a seperate marker variable col , which defaults to false, if we find a zero in the first col then we mark col variable as true, now we traverse the matrix and mark. after that we again traverse from the backward to make sure that we do not change the marker array first before the other cells.
        
        bool col0 = false; 
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    if(j == 0) {
                        col0 = true;
                    } else {
                        matrix[0][j] = 0;   
                        matrix[i][0] = 0;   
                    }
                }
            }
        }
        for(int i = matrix.size() - 1; i >= 0; i--) {
            for(int j = matrix[0].size() - 1; j >= 1 ; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if(col0) {
                matrix[i][0] = 0;
            }
        }  
    }
};