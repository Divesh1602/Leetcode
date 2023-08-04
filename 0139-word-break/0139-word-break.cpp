class Solution {
    public:
    bool solve(int x,int y,string s,set<string> st,vector<vector<int>>&dp){
        if(x+y==s.size()){
            if(st.find(s.substr(x,y))!=st.end()){
                return true;
            }
            else{
                return false;
            }
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if(st.find(s.substr(x,y))!=st.end()){
            bool op1=solve(x+y,1,s,st,dp);
            bool op2=solve(x,y+1,s,st,dp);
            return dp[x][y]=op1||op2;
        }

            return dp[x][y]=solve(x,y+1,s,st,dp);
        
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,1,s,st,dp);
    }
};
