//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
        void bfs(int i,int j,vector<vector<int>>& visited,vector<vector<char>> grid){
        int n=grid.size(),m=grid[0].size();
        visited[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                 for(int delcol=-1;delcol<=1;delcol++){
                     int nrow=row+delrow;
                     int ncol=col+delcol;
                     
                     if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && visited[nrow][ncol]==0)
                     {
                         visited[nrow][ncol]=1;
                         q.push({nrow,ncol});
                     }
                 }
            }
        }
       
      }
  
    int numIslands(vector<vector<char>>& m) {
        // Code here
        int ans=0;
       
        vector<vector<int>> visited(m.size()+1,vector<int>(m[0].size()+1,0));
       for(int i=0;i<m.size();i++){
           for(int j=0;j<m[0].size();j++){
               if(m[i][j]=='1' && !visited[i][j]){
                   ans++;
                   bfs(i,j,visited,m);
               }
           }
       }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends