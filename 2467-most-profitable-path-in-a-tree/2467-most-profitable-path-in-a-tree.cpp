class Solution {
    bool dfs(vector<int> adj[], vector<int> &path, vector<int> &visited, int node, int time) {
        path[node] = time;
        visited[node] = true;
        
        if(node == 0) return true;
        
        for(auto &adjNode:adj[node]) {
            if(!visited[adjNode]) {
                if(dfs(adj, path, visited, adjNode, time + 1)) return true;
            }
        }
        path[node] = -1;
        return false;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> adj[n];
        
        for(auto &edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> path(n, -1);
        vector<int> visited(n, 0);
        
        dfs(adj, path, visited, bob, 0);
        visited.assign(n, false);
        queue<vector<int>> q;
        
        q.push({ 0, 0, 0 });
        int ans = INT_MIN;
        while(!q.empty()) {
            int node = q.front()[0];
            int time = q.front()[1];
            int amt = q.front()[2];
            q.pop();
            
            visited[node] = true;
            
            if(path[node] == -1) {
                amt += amount[node];
            } else {
                if(time < path[node]) {
                    amt += amount[node];
                } else if(time == path[node]) 
                    amt += (amount[node] / 2);
            }
            if(adj[node].size() == 1 && node != 0) {
                ans = max(ans, amt);
            }
            
            for(auto &adjNode:adj[node]) {
                if(!visited[adjNode]) {
                    q.push({ adjNode, time + 1, amt });
                }
            }
        }
        return ans;
    }
};