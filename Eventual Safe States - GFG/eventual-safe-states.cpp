//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool chk(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathvis,vector<int>& safe){
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
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends