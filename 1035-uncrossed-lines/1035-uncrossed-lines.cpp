class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int i, int j, int n, int m, vector<vector<int>> &dp) {
        if(i >= n or j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(nums1[i] == nums2[j]) return dp[i][j] = 1 + solve(nums1, nums2, i+1, j+1, n, m, dp);

        return dp[i][j] = max(solve(nums1, nums2, i+1, j, n, m, dp), solve(nums1, nums2, i, j + 1, n, m, dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(nums1, nums2, 0, 0, n, m, dp);
    }
};