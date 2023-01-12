class Solution {
    void dfs(int node, vector<vector<int>> &adj,string &labels,vector <bool> &vis,vector <vector<int>> &cnt,vector <int> &ans){
        vis[node] = true;
        for(auto &it:adj[node]){
            if(vis[it] == false){
                dfs(it,adj,labels,vis,cnt,ans);
                for (int i = 0; i < 26; i++)
                    cnt[node][i] += cnt[it][i];
            }
        }
        ans[node] = ++cnt[node][labels[node] - 'a'];
        return;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector <vector<int>> adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector <int> ans(n);
        vector <vector<int>> cnt(n,vector <int> (26));
        vector <bool> vis(n);
        dfs(0,adj,labels,vis,cnt,ans);
        return ans;
    }
};