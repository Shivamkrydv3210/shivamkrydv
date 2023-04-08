//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        vector<int> v;
        
        int mini=0,maxi=n-1,minj=0,maxj=m-1;
       
        int t=m*n;
        int cnt=0;
        while(v.size()<t){
        for(int i=mini,j=minj;j<=maxj && v.size() < t;j++){
            cnt++;
            if(cnt==k) return a[i][j];
        else {
            v.push_back(a[i][j]);
        } 
            
        }
        mini++;
        for(int i=mini,j=maxj;i<=maxi && v.size() <t;i++){
            cnt++;
               if(cnt==k) return a[i][j];
        else {
            v.push_back(a[i][j]);
        } 
        }
        maxj--;
        for(int i=maxi,j=maxj;j>=minj && v.size() < t;j--){
               cnt++;
            if(cnt==k) return a[i][j];
        else {
            v.push_back(a[i][j]);
        }
        }
        maxi--;
        for(int i=maxi,j=minj;i>=mini && v.size()<t;i--){
            cnt++;
               if(cnt==k) return a[i][j];
        else {
            v.push_back(a[i][j]);
        } 
        }
        minj++;

        }
        return 0;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends