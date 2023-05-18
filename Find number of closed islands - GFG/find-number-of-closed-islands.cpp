//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &visited, int m, int n, int i, int j) {
        visited[i][j] = 1;
        
        int offset[5] = { -1, 0, 1, 0, -1};
        
        for(int k = 0; k < 4; k++) {
            int ni = i + offset[k];
            int nj = j + offset[k + 1];
            
            if(ni < 0 || ni >= m || nj < 0 || nj >= n || visited[ni][nj] == 1 || matrix[ni][nj] != 1) continue;
            dfs(matrix, visited, m, n, ni, nj);
        }
    }
    public:
    int closedIslands(vector<vector<int>>& matrix, int m, int n) {
        // Code here
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == 1 && !visited[0][i]) dfs(matrix, visited, m, n, 0, i);
        }
        for(int i = 0; i < n; i++) {
            if(matrix[m - 1][i] == 1 && !visited[m - 1][i]) dfs(matrix, visited, m, n, m - 1, i);
        }
        
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 1 && !visited[i][0]) dfs(matrix, visited, m, n, i, 0);
        }
        
        for(int i = 0; i < m; i++) {
            if(matrix[i][n - 1] == 1 && !visited[i][n - 1]) dfs(matrix, visited, m, n, i, n - 1);
        }
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(matrix, visited, m, n, i, j);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends