class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        
        vector<pair<long long, long long>> adj[n];
        
        for(auto &road:roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        dist[0] = 0;
        ways[0] = 1;
        
        pq.push({ 0, 0 });
        long long mod = (long long) 1e9 + 7;
        while(!pq.empty()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            
            pq.pop();
            
            for(auto &it:adj[node]) {
                long long adjNode = it.first;
                long long edgeW = it.second;
                
                if(dis + edgeW < dist[adjNode]) {
                    dist[adjNode] = dis + edgeW;
                    ways[adjNode] = ways[node];
                    pq.push({ dist[adjNode], adjNode });
                } else if(dis + edgeW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};