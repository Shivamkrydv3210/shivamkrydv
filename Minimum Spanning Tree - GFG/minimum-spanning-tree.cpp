//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	typedef pair<int,int> P;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, 0});
        
        vector<bool> vis(V, false);
        
        int sum = 0;
        
        while (!pq.empty()) {
            
            auto q = pq.top();
            
            pq.pop();
            
            int wt = q.first;
            
            int node = q.second;
            
            if (vis[node]) continue;
            
            vis[node] = true;
            
            sum += wt; 
            
            for (auto &x : adj[node]) {
            
                int neighbour_node = x[0];
                int neighbour_wt = x[1];
                
                if (!vis[neighbour_node]) {
            
                    pq.push({neighbour_wt, neighbour_node});
                }
            }
        }
        return sum;

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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends