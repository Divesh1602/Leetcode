//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
         int n=grid.size();
        int m=grid[0].size();
       
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                  q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int ans=0;
         while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
             int t=q.front().second;
            q.pop();
             if(row+1<n && grid[row+1][col]==1 && !vis[row+1][col]){
                grid[row+1][col]=2;
                vis[row+1][col]=1;
                q.push({{row+1,col},t+1});
            }
            if(row-1>=0 && grid[row-1][col]==1 && !vis[row-1][col]){
                grid[row-1][col]=2;
                vis[row-1][col]=1;
                q.push({{row-1,col},t+1});
            }
            if(col-1>=0 && grid[row][col-1]==1 && !vis[row][col-1]){
                grid[row][col-1]=2;
                 vis[row][col-1]=1;
                q.push({{row,col-1},t+1});
            }
            if(col+1<m && grid[row][col+1]==1 && !vis[row][col+1]){
                grid[row][col+1]=2;
                vis[row][col+1]=1;
                q.push({{row,col+1},t+1});
            }
           ans=t;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                  return -1;
                }
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends