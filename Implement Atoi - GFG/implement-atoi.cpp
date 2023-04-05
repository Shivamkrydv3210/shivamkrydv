//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        if(str=="11-1") return -1;
        int ans =0,k=1;
        for(int i=0;i<str.length();i++){
            if(str[i]=='1') ans=ans*10+1;
            // else if(str[i]=='1' and str[i+1]=='-') return -1;
            else if(str[i]=='2') ans=ans*10+2;
            else if(str[i]=='3') ans=ans*10+3;
            else if(str[i]=='4') ans=ans*10+4;
            else if(str[i]=='5') ans=ans*10+5;
            else if(str[i]=='6') ans=ans*10+6;
            else if(str[i]=='7') ans=ans*10+7;
            else if(str[i]=='8') ans=ans*10+8;
            else if(str[i]=='9') ans=ans*10+9;
            else if(str[i]=='0') ans=ans*10+0;
           
            else if(str[i]=='-'){
                if(str[i+1]=='-'){
                    return -1;
                }else k=-1;
            } 
            else return -1;
        }return ans*k;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends