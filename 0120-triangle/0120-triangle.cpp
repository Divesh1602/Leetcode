class Solution {
public:
    
    // long long helper(vector<vector<int>>& nums,int i,int j,int ct,int n,vector<vector<int>>& dp){
    //     if(i==n-1){
    //         return dp[i][j]=nums[i][j];
    //     }
    //     if(j==ct)
    //         return INT_MAX;
    //     if(i==n)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     long long first=helper(nums,i+1,j,ct+1,n,dp)+nums[i][j];
    //     long long second=helper(nums,i+1,j+1,ct+1,n,dp)+nums[i][j];
    //     return dp[i][j]=min(first,second);
    // }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        int m=triangle[n-1].size();
        for(int i=0;i<m;i++)
            dp[n-1][i]=triangle[n-1][i];
        
        for(int i=n-2;i>=0;i--){
             m=triangle[i].size();
            for(int j=0;j<m;j++){
                    int first=dp[i+1][j]+triangle[i][j];
                    int second=dp[i+1][j+1]+triangle[i][j];
                    
                    dp[i][j]=min(first,second);
                
            }
        }
      return dp[0][0];
        
    }
};