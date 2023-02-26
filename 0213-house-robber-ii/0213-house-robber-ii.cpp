class Solution {
public:
      int helper(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        
       dp[i]=max(helper(nums,i+1,n,dp), helper(nums,i+2,n,dp)+nums[i]);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
         vector<int> dp(nums.size(),-1),dp1(nums.size(),-1);
        return max(helper(nums,0,nums.size()-2,dp),helper(nums,1,nums.size()-1,dp1));
    }
};