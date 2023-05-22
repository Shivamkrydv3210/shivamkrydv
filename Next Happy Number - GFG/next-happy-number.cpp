//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
int happyNo(int n){
    int sum=0;
     while (n != 1) {
        sum = 0;
        while (n != 0) {
            int rem = n % 10;
            sum += rem * rem;
            n = n / 10;
        }
        n = sum;
        if (n == 4) {
            return false;
        }
    }return true;
}
int nextHappy(int n) {
    if(n==10) return 10;
    
    while(true){
        n++;
        if(happyNo(n)==1) return n;
        
    }
    return n;
}


};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends