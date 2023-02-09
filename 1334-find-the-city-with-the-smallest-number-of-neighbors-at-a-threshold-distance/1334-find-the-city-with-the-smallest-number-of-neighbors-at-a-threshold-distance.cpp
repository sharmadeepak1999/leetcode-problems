class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        
        for(auto &it:edges) {
            matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }
        
        for(int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        
        vector<int> count(n, -1);
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] <= distanceThreshold) {
                    if(count[i] == -1) count[i] = 1;
                    else count[i]++;
                }
            }
        }
        
        int minCity = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(count[i] != - 1 && count[i] < minCity) minCity = count[i];
        }
        
        for(int i = n - 1; i >= 0; i--) {
            if(count[i] == minCity) return i;
        }
        
        return -1;
    }
};