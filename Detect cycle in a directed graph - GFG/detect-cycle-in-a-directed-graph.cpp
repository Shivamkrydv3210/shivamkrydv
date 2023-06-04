//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src,vector<int>& vis,vector<int> &order,vector<int> adj[]){
        vis[src]=1;
        order[src]=1;
        for(auto x:adj[src]){
            if(vis[x]==false){
                bool cnfm=dfs(x,vis,order,adj);
                if(cnfm) return true;
            }
            else if(vis[x]==true && order[x]==true){
                return true;
            }
            
        }
            order[src]=0;
            return false;
        
        }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> order(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool c=dfs(i,vis,order,adj);
                if(c) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends