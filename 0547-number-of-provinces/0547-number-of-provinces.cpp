class DisjointSet {
    vector<int> rank, size, parent;

    public: 

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_v == ulp_u) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_v == ulp_u) return;

        if(size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        } else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};
class Solution {
public:
    /*
    void dfs(int node, int n, vector<vector<int>> &isConnected, vector<int> &visited) {
        visited[node] = 1;
        
        for(int i = 0; i < n; i++) {
            if(isConnected[node][i] && !visited[i]) dfs(i, n, isConnected, visited);
        }
    }
    */
    int findCircleNum(vector<vector<int>>& isConnected) {
        /*
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int nop = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;
            dfs(i, n, isConnected, visited);
            nop++;
        }
        return nop;
        */
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) ds.unionBySize(i, j);
            }
        }
        
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(ds.findUPar(i));
        }
        
        return s.size();
    }
};