class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited, vector<int> &check, int node) {
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;
        for(auto &adj:graph[node]) {
            if(!visited[adj]) {
                if(dfs(graph, visited, pathVisited, check, adj)) {
                    check[node] = 0;
                    return true;
                }
            } else if(pathVisited[adj]) return true;
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);
        vector<int> check(n, 0);
        vector<int> safeNodes;
        for(int i = 0; i < n; i++) {
            if(!visited[i])  dfs(graph, visited, pathVisited, check, i);
        }
        
        for(int i = 0; i < n; i++) {
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};