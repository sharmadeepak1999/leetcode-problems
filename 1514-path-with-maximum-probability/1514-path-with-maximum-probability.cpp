class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n, 0);
        vector<pair<int, double>> adj[n];
        int m = edges.size();
        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            adj[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }
        
        priority_queue<pair<int, double>> q;
        q.push({ start, 1 });
        prob[start] = 1;
        while(!q.empty()) {
            int node = q.top().first;
            double suc = q.top().second;
            
            q.pop();
            for(auto &it:adj[node]) {
                if((suc * it.second) > prob[it.first]) {
                    prob[it.first] = suc * it.second;
                    q.push({ it.first, prob[it.first] });
                }
            }
        }
        return prob[end];
    }
};