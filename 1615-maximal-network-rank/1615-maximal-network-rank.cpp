class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(auto &road:roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        
        int maxi = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int common = 0;
                if(find(adj[i].begin(), adj[i].end(), j) != end(adj[i])) {
                    common = 1;
                }
                int rank = adj[i].size() + adj[j].size() - common;
                maxi = max(maxi, rank);
            }
        }
        return maxi;
    }
};