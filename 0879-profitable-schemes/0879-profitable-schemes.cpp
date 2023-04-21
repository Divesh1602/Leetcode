class Solution {
public:
    const int MOD = 1000000007 ;
long long dp[105][105][105] ;

long long rec(int n, int currentProfit, int minProfit, vector<int>& group, vector<int>& profit, int i){
    bool isBigger = currentProfit >= minProfit ;
    int required = isBigger ? 0:minProfit-currentProfit ;
    int m = profit.size() ;
    if(n == 0 || i == m) return isBigger ? 1:0;
    if(dp[n][i][required] != -1) return dp[n][i][required] ;
    long long sum = rec(n, currentProfit, minProfit, group, profit, i+1)%MOD ;
    if(group[i]<=n){
        sum+=rec(n-group[i], currentProfit + profit[i], minProfit, group, profit, i+1)%MOD ;
    }
    //return sum%MOD ;
    return dp[n][i][required] = sum%MOD ;
} 

int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    memset(dp, -1, sizeof(dp)) ;
    return rec(n,0,minProfit,group, profit, 0);
}
};