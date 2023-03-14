class Solution {
public:
     void dfs(int i,int j,vector<vector<char>> mat,vector<vector<int>>& vis){
       vis[i][j]=1;
       int delrow[]={-1,0,1,0};
       int delcol[]={0,1,0,-1};
       int n=mat.size();
       int m=mat[0].size();
       for(int k=0;k<4;k++){
           int nrow=i+delrow[k];
           int ncol=j+delcol[k];
           
           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O' && !vis[nrow][ncol])
           dfs(nrow,ncol,mat,vis);
       }
   }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int i=0,j=0;
        while(j<m){
            if(mat[i][j]=='O' && !vis[i][j])
            dfs(i,j,mat,vis);
            j++;
        }
        j=0;
        while(i<n){
            if(mat[i][j]=='O' && !vis[i][j])
            dfs(i,j,mat,vis);
            i++;
        }
        j=m-1,i=0;
        while(i<n){
            if(mat[i][j]=='O' && !vis[i][j])
            dfs(i,j,mat,vis);
            i++;
        }
        i=n-1,j=0;
        while(j<m){
            if(mat[i][j]=='O' && !vis[i][j])
            dfs(i,j,mat,vis);
            j++;
        }
      
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(vis[i][j]==1)
                mat[i][j]='O';
                else
                mat[i][j]='X';
            }
        }
        return;
    }
};