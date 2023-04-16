class Solution {
    int MOD = 1e9 + 7;
public:
    int numWays(vector<string>& words, string& target) {
        vector<vector<int>> cnt(26, vector<int>(words[0].size()));
        for(string& word: words){
            for(int i=0; i<word.size(); i++){
                cnt[word[i]-'a'][i]++;
            }
        }
        int m = target.size(), k = words[0].size();
        vector<vector<int>> dp(m+1, vector<int>(k+1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < k; j++) {
                if (i < m) {
                    dp[i + 1][j + 1] = (dp[i+1][j+1] + ((long long)cnt[target[i] - 'a'][j] * dp[i][j])%MOD)%MOD;
                }
                dp[i][j + 1] = (dp[i][j+1] + dp[i][j])%MOD;
            }
        }
        return dp[m][k];
    }
};