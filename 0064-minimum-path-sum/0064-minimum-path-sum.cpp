class Solution {
public:
    long long helper(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp){
        
           if(i==0 && j==0){
               dp[i][j]=grid[i][j];
            return grid[i][j];
           }
         if(i<0 || j<0)
             return INT_MAX;
          if(dp[i][j]!=-1)
              return dp[i][j];
      
            long long first=helper(grid,i-1,j,dp)+grid[i][j];
      
           long long second=helper(grid,i,j-1,dp)+grid[i][j];

        return dp[i][j]=min(first,second);
        
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(grid,n-1,m-1,dp);
    }
};