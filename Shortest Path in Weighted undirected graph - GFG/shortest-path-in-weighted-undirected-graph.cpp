//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        
        for(int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        vector<int> memo(n + 1, 0);
        pq.push({ 0, 1 });
        dist[1] = 0;
        memo[1] = 1;
        
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto &it:adj[node]) {
                int nd = it.first;
                int edgeW = it.second;
                
                if(dis + edgeW < dist[nd]) {
                    dist[nd] = dis + edgeW;
                    pq.push({ dist[nd], nd });
                    memo[nd] = node;
                }
            }
        }
        if(dist[n] == INT_MAX) return {-1};
        vector<int> spath;
        int node = n;
        while(memo[node] != node) {
            spath.push_back(node);
            node = memo[node];
        }
        
        spath.push_back(1);
        reverse(spath.begin(), spath.end());
        return spath;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends