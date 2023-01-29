//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue<pair<pair<int, int>, int>> q;
	    
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int>> visited(m, vector<int>(n, 0)), distarr(m, vector<int>(n, 0));
	    
	    for(int i = 0; i < m; i++) {
	        for(int j = 0; j < n; j++) {
	            if(grid[i][j] == 1) {
	                q.push({{i, j}, 0});
	                visited[i][j] = 1;
	            }
	        }
	    }
	    
	    while(!q.empty()) {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        
	        int dist = q.front().second;
	        
	        distarr[row][col] = dist;
	        q.pop();
	        
	        vector<int> offset = {-1, 0, 1, 0, -1};
	        
	        for(int i = 0; i < 4; i++) {
	            int nrow = row + offset[i];
	            int ncol = col + offset[i + 1];
	            
	            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]) {
	                visited[nrow][ncol] = 1;
	                q.push({{nrow, ncol}, dist + 1});
	            }
	        }
	    }
	    return distarr;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends