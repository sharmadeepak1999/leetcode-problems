class Solution {
    bool search(vector<vector<char>> &board, string word, int p, int i, int j, int m, int n) {
        if(p == word.size() - 1) return word[p] == board[i][j];
        if(word[p] != board[i][j]) return false;
        int offset[5] = {-1, 0, 1, 0, -1};
        char c = board[i][j];
        board[i][j] = '0';
        bool flag = false;
        for(int k = 0; k < 4; k++) {
            int ni = i + offset[k];
            int nj = j + offset[k + 1];
            
            if(ni < 0 || ni >= m || nj < 0 || nj >= n || board[ni][nj] == '0') continue;
            if(search(board, word, p + 1, ni, nj, m, n)) {
                flag = true;
                break;
            }
        }
        board[i][j] = c;
        return flag;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(search(board, word, 0, i, j, m, n)) return true;
            }
        }
        return false;
    }
};
// A B C E
// S F C S 
// A D E E