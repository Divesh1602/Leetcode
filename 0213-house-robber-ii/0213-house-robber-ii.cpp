class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
         vector<int> dp(nums.size(),0),dp1(nums.size(),0);
        dp[0]=nums[0];
        dp1[1]=nums[1];
        for(int i=1;i<nums.size()-1;i++){
            int take=nums[i];
            if(i>1)
                take+=dp[i-2];
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);          
        }
         for(int i=2;i<nums.size();i++){
            int take=nums[i];
             if(i>1)
                take+=dp1[i-2];
            int notTake=dp1[i-1];
            dp1[i]=max(take,notTake);          
        }
        int n=dp.size(),m=dp1.size();
        return max(dp[n-2],dp1[m-1]);
    }
};