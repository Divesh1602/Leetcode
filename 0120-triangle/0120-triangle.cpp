class Solution {
public:
    
    long long helper(vector<vector<int>>& nums,int i,int j,int ct,int n,vector<vector<int>>& dp){
        if(i==n-1 && j==nums[n-1].size()-1){
            return dp[i][j]=nums[i][j];
        }
        if(j==ct)
            return INT_MAX;
        if(i==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        long long first=helper(nums,i+1,j,ct+1,n,dp)+nums[i][j];
        long long second=helper(nums,i+1,j+1,ct+1,n,dp)+nums[i][j];
        return dp[i][j]=min(first,second);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return helper(triangle,0,0,1,n,dp);
    }
};