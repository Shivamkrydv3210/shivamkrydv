//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
   
        // code here
        int rti(char ch) {
        switch (ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToDecimal(string &str) {
        int ans = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (i > 0 && rti(str[i]) > rti(str[i - 1])) {
                ans += rti(str[i]) - rti(str[i - 1]);
                i--;
            } else {
                ans += rti(str[i]);
            }
        }
        return ans;
    
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
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends