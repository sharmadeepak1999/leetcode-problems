class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // apply topo sort technique 
        
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto &p:prerequisites) {
            adj[p[0]].push_back(p[1]);
        }
        
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++) {
            for(auto &it:adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int count = 0;
        
        while(!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            
            for(auto &it:adj[course]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return count == n;
    }
};