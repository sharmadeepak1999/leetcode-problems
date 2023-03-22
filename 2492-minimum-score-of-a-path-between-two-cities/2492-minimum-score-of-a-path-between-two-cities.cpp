class Solution {
public:
    void dfs(vector<vector<pair<int, int>>> &adj, vector<int> &visited, int i) {
        visited[i] = 1;
        
        for(auto &adjNode:adj[i]) {
            if(!visited[adjNode.first])
                dfs(adj, visited, adjNode.first);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        
        for(auto road:roads) {
            adj[road[0]].push_back({road[1], road[2]});                 
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        vector<int> visited(n + 1, 0);
        dfs(adj, visited, 1);
        
        for(auto &it:visited) cout << it << ' ';
        int mini = INT_MAX;
        for(int i = 0; i < adj.size(); i++) {
            if(visited[i]) {
                for(auto &adjNode:adj[i]) {
                    mini = min(mini, adjNode.second);
                }
            }
        }
        return mini;
    }
};