//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        int cnt=0,ans=0,oddcnt=0;
       unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0) oddcnt++;
            if(oddcnt==k) cnt++;
            if(mp.find(oddcnt-k)!=mp.end()){
                cnt+=mp[oddcnt-k];
            }
            if(mp.find(oddcnt)!=mp.end()){
                mp[oddcnt]++;
            }
            else mp[oddcnt]=1;
        }return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends