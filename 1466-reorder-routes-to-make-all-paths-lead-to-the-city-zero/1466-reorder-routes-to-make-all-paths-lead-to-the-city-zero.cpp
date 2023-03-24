class Solution {
public:
    
    void dfs(vector<vector<pair<int, int>>> &adj, int node, int parent, int &count) {
        for(auto &[adjNode, sign]:adj[node]) {
            if(adjNode != parent) {
                count += sign;
                dfs(adj, adjNode, node, count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &connection:connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        int count = 0;
        dfs(adj, 0, -1, count);
        return count;
    }
};