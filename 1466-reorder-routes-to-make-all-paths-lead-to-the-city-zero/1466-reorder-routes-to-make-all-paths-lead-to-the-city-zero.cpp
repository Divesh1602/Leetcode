class Solution {
public:
   
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],-1});
            adj[connections[i][1]].push_back({connections[i][0],1});
        }
       vector<int> vis(n,0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        int ans=0;
        while(!q.empty()){
            int idx=q.front();
            q.pop();
           for(auto& [x,y]:adj[idx]){
               if(!vis[x]){
                   if(y<0)
                       ans+=-y;
                   vis[x]=1;
                   q.push(x);
               }
           }
            }
        return ans;
    }
};