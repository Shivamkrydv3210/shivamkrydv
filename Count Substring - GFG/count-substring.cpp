//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
           int cnt = 0;
    unordered_set<char> charSet;

    for (int i = 0; i < s.size(); i++) {
        charSet.clear();
        
        for (int j = i; j < s.size(); j++) {
            charSet.insert(s[j]);
            
            if (charSet.count('a') && charSet.count('b') && charSet.count('c')) {
                cnt += s.size() - j;
                break;
            }
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
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends