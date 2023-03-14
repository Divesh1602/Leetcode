class Solution {
public:
      void dfs(int curr,vector<int> adj[],vector<int>& visited){
      visited[curr]=1;
      for(auto a:adj[curr]){
          if(!visited[a])
          dfs(a,adj,visited);
      }
  }
    int findCircleNum(vector<vector<int>>& m) {
        int ans=0;int v=0;
        int i=0,j=0;
        while(i<m.size() && j<m[0].size()){
            if(m[i][j]==1)
                v++;
            i++;
            j++;
        }
        vector<int> visited(v+1,0);
        vector<int> adj[v+1];
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                    m[j][i]=0;
                }
            }
        }
        for(int i=1;i<=v;i++){
            if(visited[i]==0){
            dfs(i,adj,visited);
            ans++;
            }
        }

        return ans;
    }
};