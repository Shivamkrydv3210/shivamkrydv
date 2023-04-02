//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        int i=s.length()-1;
        while(i>=0){
            int t=s[i]-48;
            if(t%2==1) break;
            else i--;
        }
        string k="";
        for(int j=0;j<=i;j++){
            k+=s[j];
        }
        return k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends