//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        /*
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, s});
        vector<int> dist(v, 1e9);
        dist[s] = 0;
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &adjNode:adj[node]) {
                int currDist = dis + adjNode[1];
                
                if(currDist < dist[adjNode[0]]) {
                    dist[adjNode[0]] = currDist;
                    pq.push({dist[adjNode[0]], adjNode[0]});
                }
            }
        }
        return dist;
        */
        
        set<pair<int, int>> st;
        
        st.insert({0, s});
        
        vector<int> dist(v, INT_MAX);
        dist[s] = 0;
        while(!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto &adjNode:adj[node]) {
                int w = adjNode[1];
                int nd = adjNode[0];
                
                if(dis + w < dist[nd]) {
                    if(dist[nd] != INT_MAX)
                        st.erase({ dist[nd], nd });
                    dist[nd] = dis + w;
                    st.insert({ dist[nd], nd });
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends