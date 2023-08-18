class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        set<pair<int, int>> s;
        for(auto &road:roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
            s.insert({ road[0], road[1] });
            s.insert({ road[1], road[0] });
        }
        
        int maxi = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int common = 0;
                if(s.find({ i, j }) != s.end()) {
                    common = 1;
                }
                int rank = adj[i].size() + adj[j].size() - common;
                maxi = max(maxi, rank);
            }
        }
        return maxi;
    }
};