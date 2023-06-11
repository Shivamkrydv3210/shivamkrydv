//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
     bool check(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        
        return true;
    }
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    // Code here
	    int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        //BFS
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
 
            q.pop();
            
            if (check(i + 1, j, m, n) && ans[i + 1][j] == -1) {
                q.push({i + 1, j});
                ans[i + 1][j] = ans[i][j] +1;
            }

            if (check(i, j + 1, m, n) && ans[i][j + 1] == -1) {
                q.push({i, j + 1});
                ans[i][j + 1] = ans[i][j] +1;
            }

            if (check(i - 1, j, m, n) && ans[i - 1][j] == -1) {
                q.push({i - 1, j});
                ans[i - 1][j] = ans[i][j] +1;
            }

            if (check(i, j - 1, m, n) && ans[i][j - 1] == -1) {
                q.push({i, j - 1});
                ans[i][j - 1] = ans[i][j]+1 ;
            }
            
            }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends