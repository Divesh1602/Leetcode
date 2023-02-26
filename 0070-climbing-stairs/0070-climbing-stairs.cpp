class Solution {
public:
    int helper(int n,int& ans,vector<int>& dp){
       
        if(dp[n]!=-1)
            return dp[n];
        
        if(n<=1){
            dp[n]=1;
            return 1;
        }
     
         
        
        
        dp[n]=helper(n-1,ans,dp)+helper(n-2,ans,dp);
        
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans=0;
        return helper(n,ans,dp);
        
    }
};