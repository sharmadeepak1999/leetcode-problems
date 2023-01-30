class Solution {
public:
    /*
    bool isComponentBipartite(vector<vector<int>>& graph, vector<int> &type, int nodeOrg) {
        queue<int> q;
        q.push(nodeOrg);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto &adj:graph[node]) {
                if(type[adj] == -1) {
                    type[adj] = type[node] == 1 ? 0 : 1;
                    q.push(adj);
                }
                else if(type[adj] != -1 && type[adj] == type[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> type(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(type[i] == -1 && !isComponentBipartite(graph, type, i)) return false;
        }
        return true;
    }
    */
    
    bool isComponentBipartite(vector<vector<int>> &graph, vector<int> &type, int node, int prevType) {
        type[node] = !prevType;
        
        for(auto &adj:graph[node]) {
            if(type[adj] == -1 && !isComponentBipartite(graph, type, adj, !prevType)) return false;
            if(type[adj] != -1 && type[adj] == type[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> type(n, -1);
        int prevType = 0;
        for(int i = 0; i < n; i++) {
            if(type[i] == -1 && !isComponentBipartite(graph, type, i, prevType)) return false;
        }
        return true;
    }
};