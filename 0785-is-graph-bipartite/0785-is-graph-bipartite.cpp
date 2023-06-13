class Solution {
    bool bfs(vector<vector<int>>& graph, vector<int> &visited, vector<int> &color, int root) {
        queue<int> q;
        q.push(root);
        visited[root] = 1;
        color[root] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &adjNode:graph[node]) {
                if(!visited[adjNode]) {
                    visited[adjNode] = 1;
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                } else if(color[adjNode] == color[node]) return false;
            }
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
                if(!bfs(graph, visited, color, i)) return false;
            }
        }
        return true;
    }
};