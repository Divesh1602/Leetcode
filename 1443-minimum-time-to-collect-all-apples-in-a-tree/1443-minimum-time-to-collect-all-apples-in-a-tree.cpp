class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> v(n);
        for (auto& x : edges) {
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }

        return dfs(-1, 0, v, hasApple);
    }

    int dfs(int prev, int cur, vector<vector<int>>& v, vector<bool>& hasApple) {
        int ans = 0;
        for (auto x : v[cur]) {
            if (x != prev) {
                int res = dfs(cur, x, v, hasApple);
                if (res > 0 || hasApple[x]) {
                    ans += (res + 2);
                }
            }
        }
        return ans;
    }
};