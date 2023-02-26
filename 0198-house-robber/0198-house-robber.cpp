class Solution {
public:
    int helper(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        
       dp[i]=max(helper(nums,i+1,dp), helper(nums,i+2,dp)+nums[i]);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};