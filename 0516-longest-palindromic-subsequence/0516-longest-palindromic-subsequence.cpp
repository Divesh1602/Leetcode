class Solution {
public:
int rec(int i,int j,string &s,string &rev,vector<vector<int>>&dp){
    if(i<0 or j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
   if(s[i]==rev[j]){
      return dp[i][j]=1+rec(i-1,j-1,s,rev,dp);
   }
    int nottake=0;
    return dp[i][j]=max(rec(i-1,j,s,rev,dp),rec(i,j-1,s,rev,dp));
}
    int longestPalindromeSubseq(string s) {
         int n=s.length();
       string rev;
    for (int i = n - 1; i >= 0; i--)
        rev.push_back(s[i]);
        int m=rev.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));

return rec(n-1,m-1,s,rev,dp);
    }
};