class Solution {
public:
    int helper(int sum,int ct,int i,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size())
            return 0;
        if(dp[i][ct]!=-1)
            return dp[i][ct];
            // int take=helper(sum+ct*nums[i],ct+1,i+1,nums,dp);
        int take=ct*nums[i]+helper(sum+ct*nums[i],ct+1,i+1,nums,dp);
        
            int notTake=0+helper(sum,ct,i+1,nums,dp);
     return dp[i][ct]=max(take,notTake);       
    }
    int maxSatisfaction(vector<int>& sat) {
        vector<vector<int>> dp(sat.size(),vector<int>(sat.size()+1,-1));
        
        sort(sat.begin(),sat.end());
        
        return  helper(0,1,0,sat,dp);
    }
};