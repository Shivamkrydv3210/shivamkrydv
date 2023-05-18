//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& nums, int N, int goal){
        // code here
        int sum = 0, cnt = 0;
    unordered_map<int, int> mp;
   

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i]; //prefix sum array
        
        if(sum==goal) cnt++;
        if(mp.find(sum-goal)!=mp.end()){  //way to find eleent in a map
            cnt+=mp[sum-goal];   //mp[sum-goal] will give the frequency of remaining sum 
        }
        if(mp.find(sum)!=mp.end()){
            mp[sum]++;  //if sum already present in map then increase frequency of sum 
        }
        else{
            mp[sum]=1; //else just add sum in map and frequency =1
        }
    }

    return cnt;
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
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends