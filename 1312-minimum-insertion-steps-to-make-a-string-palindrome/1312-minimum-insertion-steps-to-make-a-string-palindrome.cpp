class Solution {
public:
    int helper(int i,int j,string& s,vector<vector<int>> &dp){
        if(i>j)
            return 0;
        
        if(i==j)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j])
            return dp[i][j]=2+helper(i+1,j-1,s,dp);
        
        return dp[i][j]=max(helper(i+1,j,s,dp),helper(i,j-1,s,dp));
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.length(),(vector<int> (s.length(),-1)));
        
        return s.length()-helper(0,s.length()-1,s,dp);
        
    }
};