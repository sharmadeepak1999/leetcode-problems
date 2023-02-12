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
    int removeStones(vector<vector<int>>& stones) {
        int maxRows = 0, maxCols = 0;
        
        for(auto &it:stones) {
            maxRows = max(maxRows, it[0]);
            maxCols = max(maxCols, it[1]);
        }
        
        int nodes = maxRows + maxCols + 1;
        DisjointSet ds(nodes);
        unordered_map<int, int> storedNodes;
        for(auto &it:stones) {
            int nodeRow = it[0];
            int nodeCol = maxRows + it[1] + 1;
            
            ds.unionBySize(nodeRow, nodeCol);
            storedNodes[nodeRow] = 1;
            storedNodes[nodeCol] = 1;
        }
        
        int noc = 0;
        int n = stones.size();
        for(auto &it:storedNodes) {
            if(ds.findUPar(it.first) == it.first) noc++;
        }
        return n - noc;
    }
};