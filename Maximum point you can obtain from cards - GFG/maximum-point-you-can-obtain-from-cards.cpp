//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
       vector<int> v(cardPoints.size()+1,0);
    int sum = 0;

    for (int i = 0; i < cardPoints.size(); i++) {
        sum += cardPoints[i];
       v[i]=sum;
        // cout<<v[i]<<" ";
    }
   
    int score = 0, ans = 0;
  
    for (int i = 0; i <=  k; i++) {
        int j = i+ cardPoints.size() -k-1;
        // cout<<v[j]<<" ";
        if (i == 0) {
            ans = v[j];
        } else {
            ans = v[j] - v[i - 1];
        }
        score = max(score, sum - ans);
        
    }

    return score;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends