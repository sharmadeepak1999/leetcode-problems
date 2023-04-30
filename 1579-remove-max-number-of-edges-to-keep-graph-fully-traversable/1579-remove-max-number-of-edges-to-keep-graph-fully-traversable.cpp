class Disjoint {
    
    public:
    vector<int> rank, parent;
        Disjoint(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            for(int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }
        int findUPar(int u) {
            if(parent[u] == u) return u;
            
            return parent[u] = findUPar(parent[u]);
        }
        void unionByRank(int u, int v) {
            int pu = findUPar(u);
            int pv = findUPar(v);
            
            if(pu == pv) return;
            
            if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if(rank[pv] < rank[pu]) {
                parent[pv] = pu;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    
        bool isConnected() {
            int count = 0;
            for(int i = 1; i < parent.size(); i++) {
                if(parent[i] == i) count++;
            }
            return count == 1;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Disjoint aliceDS(n);
        Disjoint bobDS(n);
        int count = 0;
        for(auto &edge:edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            if(type == 3) {
                bool req = false;
                if(aliceDS.findUPar(u) != aliceDS.findUPar(v)) {
                    req = true;
                    aliceDS.unionByRank(u, v);
                }
                if(bobDS.findUPar(u) != bobDS.findUPar(v)) {
                    req = true;
                    bobDS.unionByRank(u, v);
                }
                if(req) count++;
            }
        }
        
        for(auto &edge:edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            if(type == 1) {
                if(aliceDS.findUPar(u) != aliceDS.findUPar(v)) {
                    count++;
                    aliceDS.unionByRank(u, v);
                }
            }
            if(type == 2) {
                if(bobDS.findUPar(u) != bobDS.findUPar(v)) {
                    count++;
                    bobDS.unionByRank(u, v);
                }
            }
        }
        
        if(aliceDS.isConnected() && bobDS.isConnected()) {
            return edges.size() - count;
        }
        
        return -1;
    }
};