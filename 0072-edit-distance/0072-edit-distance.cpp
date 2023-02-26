class Solution {
public:
    int helper(string s,string s1,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==0){
            dp[i][j]=j;
            return j;
        }
        if(j==0){
            dp[i][j]=i;
            return i;
        }
        
        if(s[i-1]==s1[j-1])
            dp[i][j]= helper(s,s1,i-1,j-1,dp);
        else{
            int ans1=helper(s,s1,i,j-1,dp);
            int ans2=helper(s,s1,i-1,j,dp);
            int ans3=helper(s,s1,i-1,j-1,dp);
            dp[i][j]= 1+min(ans1,min(ans2,ans3));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();int n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(word1,word2,word1.length(),word2.length(), dp);
    }
};