//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int subarrayCount(vector<int>& nums, int N, int k) {
    // code here
    return atmost(k, nums) - atmost(k - 1, nums);
}

int atmost(int k, vector<int>& nums) {
    unordered_map<int, int> mp(nums.size()); 

    int i = 0;
    int j = 0;
    int cnt = 0;

    while (i < nums.size()) {
        mp[nums[i]]++;
        while (mp.size() > k) {
            auto it = mp.find(nums[j]);
            it->second--;
            if (it->second == 0)
                mp.erase(it);
            j++;
        }
        cnt += (i - j + 1);
        i++;
    }

    return cnt;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends