// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(vector<vector<int>>& m, vector<string>& ans, string path, int row, int col, int n) {
        
        if(row < 0 || row >= n || col >= n || col < 0 || m[row][col] == 0) {
            return;
        }
        
        if(row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }
        
        m[row][col] = 0;
        helper(m, ans, path + 'U', row - 1, col, n);
        helper(m, ans, path + 'D', row + 1, col, n);
        helper(m, ans, path + 'L', row, col - 1, n);
        helper(m, ans, path + 'R', row, col + 1, n);
        m[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // We will brute force for every direction, in the recursive function we will check first for the index out of bound, that is the row and col should be within the constraints and the current element is not a zero, then we will check if the we reached the last cell, if yes then push the current path into ans and return, else make the current element as 0 to indicate that it has been visited and then call recursion for all four direction, up down left right by modifying the row and col variable, after the recursive calls make the current cell again as 1.
        vector<string> ans;
        string path = "";
        helper(m, ans, path, 0, 0, n);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends