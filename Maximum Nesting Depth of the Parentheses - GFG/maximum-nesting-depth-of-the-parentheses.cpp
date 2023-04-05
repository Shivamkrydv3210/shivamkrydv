//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
        // code here
         int maxDepth(string s) {
       stack<char> st;
       int cnt=0,i=0;
       int max_cnt=0;
       for(int i=0;i<s.size();i++){

           if(s[i]=='('){
               st.push('(');
               cnt++;
                if(cnt > max_cnt) max_cnt = cnt;
            }
            else if(s[i]==')'){
               if(st.top()=='('){
               st.pop();
               cnt--;
            }
            }
            else {
               continue;
               }
         }
       return max_cnt;
    
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
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends