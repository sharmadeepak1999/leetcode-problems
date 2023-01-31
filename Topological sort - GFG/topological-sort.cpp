//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
// 	void dfs(vector<int> adj[], vector<int> &visited, stack<int> &s, int node) {
// 	    visited[node] = 1;
	    
// 	    for(auto &adjNode:adj[node]) {
// 	        if(!visited[adjNode]) {
// 	            dfs(adj, visited, s, adjNode);
// 	        }
// 	    }
// 	    s.push(node);
// 	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	   // // code here
	   // vector<int> visited(v, 0);
	   // stack<int> s;
	   // for(int i = 0; i < v; i++) {
	   //     if(!visited[i]) dfs(adj, visited, s, i);
	   // }   
	   // vector<int> ans;
	    
	   // while(!s.empty()) {
	   //     ans.push_back(s.top());
	   //     s.pop();
	   // }
	   // return ans;
	   
	   vector<int> topo;
	   vector<int> indegree(v, 0);
	   
	   for(int i = 0; i < v; i++) {
	       for(auto &node:adj[i]) indegree[node]++;
	   }
	   
	   queue<int> q;
	   
	   for(int i = 0; i < v; i++) {
	       if(indegree[i] == 0) q.push(i);
	   }
	   
	   while(!q.empty()) {
	       int node = q.front();
	       q.pop();
	       
	       topo.push_back(node);
	       
	       for(auto &adjNode:adj[node]) {
	           indegree[adjNode]--;
	           if(indegree[adjNode] == 0) q.push(adjNode);
	       }
	   }
	   return topo;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends