class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> ans;
        int M=m;
        for(int i=0;i<n;i++){
            if(group[i]==-1)group[i]=M++;
        }
        vector<int> item_adj[n],item_indegree(n,0);
        vector<int> group_adj[M],group_indegree(M,0);

        for(int i=0;i<n;i++)
        {
            for(int par:beforeItems[i]){
                item_adj[par].push_back(i);
                item_indegree[i]++;
                if(group[i]!=group[par]){
                    group_adj[group[par]].push_back(group[i]);
                    group_indegree[group[i]]++;
                }
            }
        }
        vector<int> itm=topo_sort(item_adj,item_indegree,n);
        vector<int> grp=topo_sort(group_adj,group_indegree,M);
        if(itm.empty() || grp.empty())return {};

        vector<int> grouping[M];
        for(int i:itm){
            grouping[group[i]].push_back(i);
        }
        for(int g:grp){
            ans.insert(ans.end(),grouping[g].begin(),grouping[g].end());
        }

        return ans;
    }
    vector<int> topo_sort(vector<int> adj[],vector<int>& indegree,int N){
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<N;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
                if(--indegree[it]==0)q.push(it);
        }
        return topo.size()==N?topo:vector<int>();
    }
};
