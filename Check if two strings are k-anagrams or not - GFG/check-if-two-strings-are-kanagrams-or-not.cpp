//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
        if(str1.length()!=str2.length()) return false ;
        unordered_map<char,int> mp;
        for(auto x:str1){
            mp[x]++;
        }
        for(int i=0;i<str2.length();i++){
            if(mp.count(str2[i])>0){
                mp[str2[i]]--;
            }
        }
        int count=0;
        for(auto x:mp){
            if(x.second>0) count+=x.second;
        }
        if(count>k)return false;
        else return true;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends