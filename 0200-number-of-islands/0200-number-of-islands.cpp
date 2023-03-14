class Solution {
public:
            void bfs(int i,int j,vector<vector<int>>& visited,vector<vector<char>> grid){
        int n=grid.size(),m=grid[0].size();
        visited[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row+1<n && grid[row+1][col]=='1' && visited[row+1][col]==0){
                visited[row+1][col]=1;
                q.push({row+1,col});
            }
            if(row-1>=0 && grid[row-1][col]=='1' && visited[row-1][col]==0){
                visited[row-1][col]=1;
                q.push({row-1,col});
            }
            if(col-1>=0 && grid[row][col-1]=='1' && visited[row][col-1]==0){
                visited[row][col-1]=1;
                q.push({row,col-1});
            }
            if(col+1<m && grid[row][col+1]=='1' && visited[row][col+1]==0){
                visited[row][col+1]=1;
                q.push({row,col+1});
            }
        }
       
      }
    int numIslands(vector<vector<char>>& m) {
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