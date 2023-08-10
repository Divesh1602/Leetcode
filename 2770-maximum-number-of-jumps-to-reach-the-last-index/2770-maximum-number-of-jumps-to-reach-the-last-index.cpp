class Solution {
public:
   
    int helper(vector<int>& nums,int target,int i,vector<int>& dp){
        
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
       int ans=INT_MIN;
        for(int j=i+1;j<nums.size();j++){
            if(abs(nums[i]-nums[j])<=target){
                ans=max((helper(nums,target,j,dp)+1),ans);
            }
        }
       
        return dp[i]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int i=0;
        vector<int> dp(nums.size(),-1);

        int ans=helper(nums,target,i,dp);
        if(ans<0)
            return -1;
        return ans;
    }
};