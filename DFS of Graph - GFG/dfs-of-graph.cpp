//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void helper(vector<int> adj[], vector<int> &visited, vector<int> &dfs, int node) {
        if(visited[node]) return;
        visited[node] = 1;
        dfs.push_back(node);
        
        for(auto &n:adj[node]) {
            helper(adj, visited, dfs, n);
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> dfs;
        vector<int> visited(v, 0);
        
        helper(adj, visited, dfs, 0);
        return dfs;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends