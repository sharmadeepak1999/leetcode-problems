class Solution {
    bool dfs(vector<vector<int>>& graph, vector<int> &visited, vector<int> &color, int node) {
        visited[node] = 1;
        for(auto &adjNode:graph[node]) {
            if(!visited[adjNode]) {
                color[adjNode] = !color[node];
                if(!dfs(graph, visited, color, adjNode)) return false;
            } else if(color[adjNode] == color[node]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<int> visited(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                color[i] = 0;
                if(!dfs(graph, visited, color, i)) return false;
            }
        }
        return true;
    }
};