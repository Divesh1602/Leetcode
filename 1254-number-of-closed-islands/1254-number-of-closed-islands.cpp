class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,int i,int j){
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int nrow=row+delrow[j];
                int ncol=col+delcol[j];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
            
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
       int i=0,j=0;
        while(j<m){
            if(grid[i][j]==0 && !vis[i][j])
                bfs(grid,vis,i,j);
            j++;
        }
        j=0;
        while(i<n){
            if(grid[i][j]==0 && !vis[i][j])
                bfs(grid,vis,i,j);
            i++;
        }
        i=n-1;
        while(j<m){
            if(grid[i][j]==0 && !vis[i][j])
                bfs(grid,vis,i,j);
            j++;
        }
        i=0,j=m-1;
        while(i<n){
            if(grid[i][j]==0 && !vis[i][j])
                bfs(grid,vis,i,j);
            i++;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    ans++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        
        
        
        
        return ans;
        
    }
};