class Solution {
    void dfs(vector<int> adj[], vector<int> &visited, int node) {
        visited[node] = 1;
        for(auto &adjNode:adj[node]) {
            if(!visited[adjNode]) {
                dfs(adj, visited, adjNode);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(adj, visited, i);
                count++;
            }
        }
        return count;
    }
};