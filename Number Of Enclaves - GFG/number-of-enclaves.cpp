//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   void bfs(int i,int j,vector<vector<int>> mat,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
       q.push({i,j});
       vis[i][j]=1;
       int delrow[]={-1,0,1,0};
       int delcol[]={0,1,0,-1};
       int n=mat.size();
       int m=mat[0].size();
          
          while(!q.empty()){
              int row=q.front().first;
              int col=q.front().second;
              q.pop();
       for(int k=0;k<4;k++){
           int nrow=row+delrow[k];
           int ncol=col+delcol[k];
           
           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==1 && !vis[nrow][ncol]){
           q.push({nrow,ncol});
           vis[nrow][ncol]=1;
           }
       }
              }
   }
    int numberOfEnclaves(vector<vector<int>> &mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int i=0,j=0;
        while(j<m){
            if(mat[i][j]==1 && !vis[i][j])
            bfs(i,j,mat,vis);
            j++;
        }
        j=0;
        while(i<n){
            if(mat[i][j]==1 && !vis[i][j])
            bfs(i,j,mat,vis);
            i++;
        }
        j=m-1,i=0;
        while(i<n){
            if(mat[i][j]==1 && !vis[i][j])
            bfs(i,j,mat,vis);
            i++;
        }
        i=n-1,j=0;
        while(j<m){
            if(mat[i][j]==1 && !vis[i][j])
            bfs(i,j,mat,vis);
            j++;
        }
        int ans=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(vis[i][j]==0 && mat[i][j]==1)
                    ans++;
               
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends