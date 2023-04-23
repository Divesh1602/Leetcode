class Solution {
public:
    int mod=1e9+7;
    int helper(string& s,int k,int i,vector<int>& dp){
        if(i>=s.length())
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        for(int j=1;j<=s.length()-i;j++){
            string s1=s.substr(i,j);
            if(s1.length()>9)
                break;
            int num=stoi(s1);
            if(num==0)
                return dp[i]=0;
            if(num<=k){
                ans=(ans+helper(s,k,i+j,dp))%mod;
                dp[i]=ans;
            }
                
        }
        return dp[i];
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.length(),-1);
        return helper(s,k,0,dp);
    }
};
