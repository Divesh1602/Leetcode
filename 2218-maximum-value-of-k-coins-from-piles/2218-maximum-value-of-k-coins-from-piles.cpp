class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& piles, int k,int i,int n,int sum){
        if(k==0 ||i>=n){
            return dp[k][i]=0 ;
        }
        
        if(dp[k][i]!=-1)return dp[k][i];
        int p=k;
        int ans=sum+helper(piles,k,i+1,n,0);
        for(int j=0;j<piles[i].size()&&k>0;j++){
            k--;sum+=piles[i][j];
           ans=max(ans,sum+helper(piles,k,i+1,n,0));
        }
        return dp[p][i]=ans;
        

    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>d(2001,vector<int>(1001,-1));
        dp=d;
       return helper(piles,k,0,piles.size(),0);
       
    }
    
};