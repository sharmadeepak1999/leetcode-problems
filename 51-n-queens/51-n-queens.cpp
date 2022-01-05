#include<bits/stdc++.h>
class Solution {
public:
    int board[11][11];
    
    bool isPossible(int n, int row, int column) {
        for(int i = row - 1; i >= 0; i--) {
            if(board[i][column] == 1){
                return false;
            }
        }
        for(int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 1) {
                return false;
            }
        }
        for(int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 1) {
                return false;
            }
        }
        return true;
    }
    
    void solveNQueensHelper(int n, int row, vector<vector<string>> &solutions) {
        if(row == n) {
            vector<string> sol;
            for(int i = 0; i < n; i++) {
                string s;
                for(int j = 0; j < n; j++) {
                    if(board[i][j] == 1) {
                        s.append("Q");
                    } else {
                        s.append(".");
                    }
                }
                sol.push_back(s);
            }
            solutions.push_back(sol);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(isPossible(n, row, i)) {
                board[row][i] = 1;
                solveNQueensHelper(n, row + 1, solutions);
                board[row][i] = 0;
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        memset(board, 0, 11 * 11 * sizeof(int));
        vector<vector<string>> solutions;
        solveNQueensHelper(n, 0, solutions);
        return solutions;
    }
};