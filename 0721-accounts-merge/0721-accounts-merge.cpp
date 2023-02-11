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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        DisjointSet ds(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mp.find(accounts[i][j]) != mp.end()) {
                    ds.unionBySize(mp[accounts[i][j]], i);
                } else mp[accounts[i][j]] = i;
            }
        }
        
        vector<string> mergedMail[n];
        
        for(auto &it:mp) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0; i < n; i++) {
            if(!mergedMail[i].empty()) {
                vector<string> temp;
                
                temp.push_back(accounts[i][0]);
                sort(mergedMail[i].begin(), mergedMail[i].end());
                for(auto &it:mergedMail[i]) {
                    temp.push_back(it);
                }
                
                ans.push_back(temp);
            }
        }
        return ans;
    }
};