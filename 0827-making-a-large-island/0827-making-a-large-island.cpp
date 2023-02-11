class DisjointSet {

    public: 
    vector<int> rank, size, parent;

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
    void generateDS(vector<vector<int>> &grid, DisjointSet &ds, int i, int j, int n) {
        int offset[5] = {-1, 0, 1, 0, -1};
        
        int node = i * n + j;
        
        for(int k = 0; k < 4; k++) {
            int row = i + offset[k];
            int col = j + offset[k + 1]; 
            int adjNode = row * n + col;
            if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] && ds.findUPar(node) != ds.findUPar(adjNode)) {
                ds.unionBySize(node, adjNode);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    generateDS(grid, ds, i, j, n);
                }
            }
        }
        
        int largestIsland = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    int offset[5] = {-1, 0, 1, 0, -1};
                    unordered_set<int> s;
                    for(int k = 0; k < 4; k++) {
                        int row = i + offset[k];
                        int col = j + offset[k + 1]; 
                        int adjNode = row * n + col;
                        if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col]) {
                            s.insert(ds.findUPar(adjNode));
                        }
                    }
                    int currIsland = 1;
                    
                    for(auto &p:s) {
                        currIsland += ds.size[p];
                    }
                    largestIsland = max(largestIsland, currIsland);
                }
            }
        }
        
        for(int i = 0; i < n * n; i++) {
            largestIsland = max(largestIsland, ds.size[ds.findUPar(i)]);
        }
        return largestIsland;
    }
};