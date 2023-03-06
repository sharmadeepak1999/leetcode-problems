class Solution {
public:
    // A B C E
    // S F E S
    // A D E E
    bool isPossible(vector<vector<char>>& board, string word, int i, int j) {
        if(word == "") return true;

        int m = board.size(), n = board[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[0]) return false;
    
        board[i][j] = '0';   
        bool status = isPossible(board, word.substr(1), i - 1, j) || isPossible(board, word.substr(1), i + 1, j) || isPossible(board, word.substr(1), i, j - 1) || isPossible(board, word.substr(1), i, j + 1);

        board[i][j] = word[0];   
        return status;
}
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(isPossible(board, word, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};