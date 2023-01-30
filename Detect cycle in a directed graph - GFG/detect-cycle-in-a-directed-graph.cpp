//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int> adj[], vector<int> &visited, vector<int> &pathVisited, int node) {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto &adjNode:adj[node]) {
            if(visited[adjNode] && pathVisited[adjNode]) return true;
            if(!visited[adjNode] && dfs(adj, visited, pathVisited, adjNode)) return true;
        }
        pathVisited[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int> visited(v, 0);
        vector<int> pathVisited(v, 0);
        
        for(int i = 0; i < v; i++) {
            if(!visited[i] && dfs(adj, visited, pathVisited, i)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends