class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        long long n = q.size();
        long long dp[n+1];
        dp[n] = 0;
        for (long long i=n-1; i>=0; i--)
            dp[i] = max(dp[i+1], q[i][0]+dp[min(n,q[i][1]+i+1)]);
        return dp[0];
    }
};