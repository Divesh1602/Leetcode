class Solution {
public:
     bool chk(int node,vector<vector<int>>& adj,vector<int> &vis,vector<int> &pathvis,vector<int>& safe){
      vis[node]=1;
      pathvis[node]=1;
      safe[node]=0;
      for(auto a:adj[node]){
          if(!vis[a]){
              if(chk(a,adj,vis,pathvis,safe))
              return true;
          }
          else if(pathvis[a])
          return true;
      }
      safe[node]=1;
      pathvis[node]=0;
      return false;
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int v=adj.size();
         vector<int> vis(v,0);
        vector<int> pathvis(v,0);
        vector<int> ans;
        vector<int> safe(v);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                chk(i,adj,vis,pathvis,safe);
            }
        }
       for(int i=0;i<v;i++)
       if(safe[i]==1)
       ans.push_back(i);
       
       return ans;
    }
};