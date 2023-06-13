//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet {
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n);
        
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = i;
        }
    }
    int findUPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int uPar = findUPar(u);
        int vPar = findUPar(v);
        
        if(uPar == vPar) return;
        
        if(rank[uPar] < rank[vPar]) {
            parent[uPar] = vPar;
        } else if(rank[vPar] < rank[uPar]) parent[vPar] = uPar;
        else {
            parent[uPar] = vPar;
            rank[vPar]++;
        }
    }
    
    void unionBySize(int u, int v) {
        int uPar = findUPar(u);
        int vPar = findUPar(v);
        
        if(uPar == vPar) return;
        if(size[uPar] < size[vPar]) {
            parent[uPar] = vPar;
            size[vPar] += size[uPar];
        } else {
            parent[vPar] = uPar;
            size[uPar] += size[vPar];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>> edges;
        
       for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, node, adjNode});
            }
        }

        
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(n);
        
        int sum = 0;
        for(auto &it:edges) {
            int u = it[1];
            int v = it[2];
            int wt = it[0];
            
            if(ds.findUPar(u) != ds.findUPar(v)) {
                sum += wt;
                ds.unionByRank(u, v);
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends