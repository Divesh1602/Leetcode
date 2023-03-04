class Solution {
public:
    int helper(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m)
            return -1e8;
        
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        
        
        if(i==n-1){
            if(j1==j2)
                return dp[i][j1][j2]=grid[i][j1];
            else
                return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
        }
        
        int mx=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++){
             for(int dj2=-1;dj2<=1;dj2++){
                 int val;
                 if(j1==j2)
                     val=grid[i][j1];
                 else
                      val=grid[i][j1]+grid[i][j2];
                 
                 val+=helper(i+1,j1+dj1,j2+dj2,n,m,grid,dp);
                 mx=max(mx,val);
             }
        }
        return dp[i][j1][j2]=mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(0,0,m-1,n,m,grid,dp);
    }
};