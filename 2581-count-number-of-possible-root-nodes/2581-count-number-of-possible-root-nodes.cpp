class Solution {
public:
    int getAns(vector<vector<int>> &adj, map<pair<int, int>, bool> &mp, vector<int> &visited, int node) {
        visited[node] = 1;
        int ans = 0;
        for(auto &adjNode:adj[node]) {
            if(!visited[adjNode]) {
                ans += (mp.count({ node, adjNode }) + getAns(adj, mp, visited, adjNode));
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>> &adj, map<pair<int, int>, bool> &mp, vector<int> &visited, int k, int node, int ans, int &res) {
        if(ans >= k) res++;
        visited[node] = 1;
        for(auto &adjNode:adj[node]) {
            if(!visited[adjNode]) {
                dfs(adj, mp, visited, k, adjNode, ans - mp.count({ node, adjNode }) + mp.count({ adjNode, node }), res);
            }
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        
        map<pair<int, int>, bool> mp;
        for(auto &edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        for(auto &guess:guesses) {
            mp[{ guess[0], guess[1] }] = true;
        }
        
        vector<int> visited(n, 0);
        
        int ans = getAns(adj, mp, visited, 0);
        fill(visited.begin(), visited.end(), 0);
        int res = 0;
        dfs(adj, mp, visited, k, 0, ans, res);
        return res;
    }
};