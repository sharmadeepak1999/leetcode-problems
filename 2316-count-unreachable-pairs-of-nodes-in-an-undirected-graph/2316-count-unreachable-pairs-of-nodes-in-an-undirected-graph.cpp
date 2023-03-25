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
        long long nop = 0;
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        for(auto &edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        long long total = n;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                long long count = 0;
                dfs(adj, visited, i, count);
                total -= count;
                nop += count * total;
            }
        }
        
        return nop;
    }
};