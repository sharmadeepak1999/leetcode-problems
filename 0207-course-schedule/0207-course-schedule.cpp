class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto &it:prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            count++;
            
            for(auto &adjNode:adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        
        return count == numCourses;
    }
};