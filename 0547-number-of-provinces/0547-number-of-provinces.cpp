class Solution {
public:
    void dfs(int node, int n, vector<vector<int>> &isConnected, vector<int> &visited) {
        visited[node] = 1;
        
        for(int i = 0; i < n; i++) {
            if(isConnected[node][i] && !visited[i]) dfs(i, n, isConnected, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int nop = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            dfs(i, n, isConnected, visited);
            nop++;
        }
        return nop;
    }
};