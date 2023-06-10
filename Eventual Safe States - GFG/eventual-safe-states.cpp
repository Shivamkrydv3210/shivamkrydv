//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool DFS(vector<int> graph[], vector<bool> &vis, vector<bool> &order,vector<int> &ans, int src)
    {
         vis[src]=true; 
         order[src] = true;
         for(auto x:graph[src])
         {
             if(!vis[x]){
                 if(DFS(graph,vis,order,ans,x)){
                 return true;
                 }
             }
             else if(order[x]){
                 return true;
             }
         }
        order[src]=false;
        ans.push_back(src);
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
        // code here
        vector<int> ans;   
         vector<bool> vis(V,false); 
         vector<bool> order(V,false);
         
         for(int i = 0; i < V; i++)
         {
             if(!vis[i])
                 DFS(graph,vis,order,ans,i);
         }
         sort(ans.begin(),ans.end());
         return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends