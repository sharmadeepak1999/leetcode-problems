class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        for(auto &it:prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        int count = 0;
        queue<int> q;
        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                visited[i] = 1;
                count++;
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto &adjNode:adj[node]) {
                if(!visited[adjNode]) {
                    indegree[adjNode]--;
                    if(indegree[adjNode] == 0) {
                        count++;
                        q.push(adjNode);
                    }
                }
            }
        }
        
        return count == numCourses;
    }
};