class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        
        for(auto &flight:flights) {
            int src = flight[0];
            int dst = flight[1];
            int cost = flight[2];
            
            adj[src].push_back({ dst, cost });
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, INT_MAX);
        
        q.push({ 0, { src, 0 } });
        dist[src] = 0;
        
        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            
            q.pop();
            if(stops > k) continue;
            for(auto &it:adj[node]) {
                int adjNode = it.first;
                int cost = it.second;
                
                if(dis + cost < dist[adjNode] && stops <= k) {
                    dist[adjNode] = dis + cost;
                    q.push({ stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        
        return dist[dst];
    }
};