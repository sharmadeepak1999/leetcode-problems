class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        /*
        unordered_map<int, unordered_map<int, vector<int>>> mp;

        int m = mat.size();
        int n = mat[0].size();
        
        int c = 0;
        while(c < n) {
            int i = 0;
            int j = c;
            int x = 0, y = c;
            vector<int> ele;
            while(i < m && j < n) {
                ele.push_back(mat[i++][j++]);
            }
            sort(ele.begin(), ele.end());
            mp[x][y] = ele;
            c++;
        }
        
        int r = 1;
        
        while(r < m) {
            int i = r;
            int j = 0;
            int x = r, y = 0;
            vector<int> ele;
            while(i < m && j < n) {
                ele.push_back(mat[i++][j++]);
            }
            sort(ele.begin(), ele.end());
            mp[x][y] = ele;
            r++;
        }
        
        
        c = 0;
        while(c < n) {
            int i = 0;
            int j = c;
            vector<int> ele = mp[i][j];
            int ind = 0;
            while(i < m && j < n) {
                mat[i++][j++] = ele[ind++];
            }
            c++;
        }
        
        r = 1;
        
        while(r < m) {
            int i = r;
            int j = 0;
            
            vector<int> ele = mp[i][j];
            int ind = 0;
            while(i < m && j < n) {
                mat[i++][j++] = ele[ind++];
            }
            r++;
        }
        
        return mat;
        */
        
        unordered_map<int, vector<int>> mp;
        
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[j - i].push_back(mat[i][j]);
            }
        }
        
        for(auto &it:mp) sort(it.second.begin(), it.second.end());
        
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                mat[i][j] = mp[j - i].back();
                mp[j - i].pop_back();
            }
        }
        
        return mat;
    }
};