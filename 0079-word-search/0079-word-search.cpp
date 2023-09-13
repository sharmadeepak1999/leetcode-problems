class Solution {
    bool search(vector<vector<char>> &board, vector<vector<int>> &visited, string word, int pos, int i, int j, int m, int n) {
        if(pos == word.size()) return true;

        int offset[5] = {-1, 0, 1, 0, -1};
        
        for(int k = 0; k < 4; k++) {
            int ni = i + offset[k];
            int nj = j + offset[k + 1];
            
            if(ni < 0 || ni >= m || nj < 0 || nj >= n || visited[ni][nj] == 1 || board[ni][nj] != word[pos]) continue;
            visited[ni][nj] = 1;
            if(search(board, visited, word, pos + 1, ni, nj, m, n)) return true;
            visited[ni][nj] = 0;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<int>> visited(m, vector<int>(n, 0));
                    visited[i][j] = 1;
                    if(search(board, visited, word, 1, i, j, m, n)) return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};