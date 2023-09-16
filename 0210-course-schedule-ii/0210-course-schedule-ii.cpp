class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        
        for(auto &it:prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto &adjNode:adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};