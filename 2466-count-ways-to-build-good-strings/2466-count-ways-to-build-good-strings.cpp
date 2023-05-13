class Solution {
public:
   long long mode = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(high+1);
        dp[0] = 1;
        for(int i=1;i<=high;i++)
        {
            if(i-zero>=0)dp[i] = (dp[i]+dp[i-zero])%mode;
            if(i-one>=0) dp[i] = (dp[i]+dp[i-one])%mode;
        }
        long long ans = 0;
        while(low<=high)ans = (ans+dp[low++])%mode;
        return ans;
    }
};