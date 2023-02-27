class Solution {
public:
    int m,n;
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i>=m || j>=n)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
       if(grid[i][j])
       {
           dp[i][j]=0;
           return 0;
       }
        
        if(i==m-1 && j==n-1)
           {
            dp[i][j]=1;
            return 1;
        }
        
        else
        return dp[i][j]=helper(i+1,j,grid,dp)+helper(i,j+1,grid,dp);
            
        }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         m=obstacleGrid.size();
         n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(0,0,obstacleGrid,dp);
    }
};