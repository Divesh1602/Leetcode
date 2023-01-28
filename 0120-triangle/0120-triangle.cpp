class Solution {
public:
    int helper(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp )
    {
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        int left=helper(i+1,j,n,triangle,dp );
        int right=helper(i+1,j+1,n,triangle,dp );
        dp[i][j]=min(left,right)+triangle[i][j];
        return dp[i][j];

    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        int m=n;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,0,n,triangle,dp );
    }
};