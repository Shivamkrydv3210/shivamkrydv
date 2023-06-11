//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> v;
   
  void dfs(int i, int j, string s, int n, vector<vector<int>>& m, vector<vector<int>>& vis) {
    if (i < 0 || i >= n || j < 0 || j >= n) return;
    if (vis[i][j] == 1 || m[i][j] == 0) return;

    if (i == n - 1 && j == n - 1) {
        v.push_back(s);
        return;
    }
    vis[i][j] = 1;

    dfs(i + 1, j, s + 'D', n, m, vis);
    dfs(i, j + 1, s + 'R', n, m, vis);
    dfs(i - 1, j, s + 'U', n, m, vis);
    dfs(i, j - 1, s + 'L', n, m, vis);

    vis[i][j] = 0;  //kyuki agar wapas backtrack karna pade toh jo 1 kiye the use wapas se 0 kar do kyuki bad me ho sakta h yeh unvisit karna kaam me aa jaye 
}

    vector<string> findPath(vector<vector<int>>& m, int n) {
    v.clear();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int i = 0, j = 0;
    if (m[i][j] == 0 || m[n - 1][n - 1] == 0) return v;
    string s = "";
    dfs(0, 0, s, n, m, vis);
    sort(v.begin(), v.end());
    return v;
}

};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends