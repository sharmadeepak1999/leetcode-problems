class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int node, long long &count) {
        count++;
        visited[node] = 1;
        for(auto &adjNode:adj[node]) {
            if(!visited[adjNode]) {
                dfs(adj, visited, adjNode, count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) return ((long long) n * (n - 1)) / 2;
        long long nop = 0;
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        for(auto &edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<long long> nodesInCc;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                long long count = 0;
                dfs(adj, visited, i, count);
                nodesInCc.push_back(count);
            }
        }
        
        for(int i = 0; i < nodesInCc.size(); i++) {
            for(int j = i + 1; j < nodesInCc.size(); j++) {
                nop += nodesInCc[i] * nodesInCc[j];
            }
        }
        
        return nop;
    }
};