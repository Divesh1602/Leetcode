class Solution {
public:
     bool chk(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathvis,vector<int>& ans){
      vis[node]=1;
      pathvis[node]=1;
     
      for(auto a:adj[node]){
          if(!vis[a]){
              if(chk(a,adj,vis,pathvis,ans))
              return true;
          }
          else if(pathvis[a])
          return true;
      }
      pathvis[node]=0;
          ans.push_back(node);
      return false;
  }
    bool canFinish(int v, vector<vector<int>>& pre,vector<int>& ans) {
        vector<int> adj[v];
        for(auto a:pre)
        {
            adj[a[0]].push_back(a[1]);
        }
        vector<int> vis(v,0);
        vector<int> pathvis(v,0);
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                
                if(chk(i,adj,vis,pathvis,ans))
                return false;
            }
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        if(canFinish(numCourses,pre,ans))
            return ans;
                
            return {};    
                
    }
};