class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &type, int node, int prevType) {
        type[node] = !prevType;
        
        for(auto &adjNode:graph[node]) {
            if(type[adjNode] == type[node]) return false;
            if(type[adjNode] == -1 && !dfs(graph, type, adjNode, !prevType)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> type(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(type[i] == -1) {
                if(!dfs(graph, type, i, 0)) return false;
            }
        }
        return true;
    }
};