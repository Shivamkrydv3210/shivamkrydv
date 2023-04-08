//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
          unordered_map<int,int> mp;
         vector<int> v;
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    // int n=nums.size();
    for(auto x:mp){
        if(x.second>n/3 ) {
            v.push_back(x.first);
        }
    }
    sort(v.begin(), v.end());
    vector<int> v1;
    v1.push_back(-1);
    if(v.size()) return v;
    else return v1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends