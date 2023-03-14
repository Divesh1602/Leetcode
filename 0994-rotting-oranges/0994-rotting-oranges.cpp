class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int ans=0;
        while(true){
            ans++;
            int size=q.size();
           
            if(q.empty())
                return ans;
        }
        return 0;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
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