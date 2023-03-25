class Solution {
public:
    void bfs(vector<vector<int>>& adj,vector<int>& vis,int i,long long& ct){
        vis[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            ct++;
            int idx=q.front();
            q.pop();
            
            for(auto a:adj[idx]){
                if(!vis[a])
                {
                    vis[a]=1;
                    q.push(a);
                }
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n,vector<int>());
         for(auto a:edges){
             adj[a[0]].push_back(a[1]);
             adj[a[1]].push_back(a[0]);
         }        
        vector<int> vis(n,0);
        vector<long long> nums;
        long long ct=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(adj,vis,i,ct);
                nums.push_back(ct);
                ct=0;
            }
        }
        
        if(nums.size()==1)
            return 0;
        long long ans=0;
        long long ele=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            ans+=(long long)(nums[i])*(long long)(ele);
            ele+=nums[i];
        }
        return ans;
    }
};