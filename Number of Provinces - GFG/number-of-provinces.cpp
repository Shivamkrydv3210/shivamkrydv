//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int src, vector<int>& vis, vector<vector<int>>& adjLs) {
    vis[src] = 1;
    for (auto x : adjLs[src]) {
        if (!vis[x]) {
            dfs(x, vis, adjLs);
        }
    }
}

int numProvinces(vector<vector<int>>& adj, int V) {
    vector<vector<int>> adjLs(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    int cnt = 0;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (vis[i] != 1) {
            dfs(i, vis, adjLs);
            cnt++;
        }
    }
    return cnt;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends