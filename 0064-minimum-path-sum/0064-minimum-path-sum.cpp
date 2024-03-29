class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)
                     dp[0][0]=grid[0][0];
                else{
                int first=INT_MAX,second=INT_MAX;
                if(i>0)
                    first=dp[i-1][j]+grid[i][j];
                if(j>0)
                    second=dp[i][j-1]+grid[i][j];
                
                dp[i][j]=min(first,second);
                }
            }
        }
        return dp[n-1][m-1];
    }
};