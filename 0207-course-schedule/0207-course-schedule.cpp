class Solution {
public:
    bool detectCycle(vector<int> adj[], vector<int> &visited, vector<int> &pathVisited, int node) {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto &adjNode:adj[node]) {
            if(!visited[adjNode]) {
                if(detectCycle(adj, visited, pathVisited, adjNode)) return true;
            } else if(pathVisited[adjNode]) return true;
        }
        pathVisited[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(auto &it:prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> visited(numCourses, 0), pathVisited(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(detectCycle(adj, visited, pathVisited, i)) return false;
            }
        }
        return true;
    }
};