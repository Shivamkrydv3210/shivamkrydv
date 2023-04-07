//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
    int p[n], n1[n];
    int pCount = 0, nCount = 0;

    for(int i=0; i<n; i++){
        if(arr[i]>=0){
            p[pCount++] = arr[i];
        }else{
            n1[nCount++] = arr[i];
        }
    }
    
    int i=0, j=0, k=0;
    while(i < pCount && j < nCount){
        arr[k++]=p[i++];
        arr[k++]=n1[j++];
    }
    
    while(i < pCount){
        arr[k++] = p[i++];
    }
    
    while(j < nCount){
        arr[k++] = n1[j++];
    }
}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends