//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int curr,vector<int> adj[],vector<int>& visited){
      visited[curr]=1;
      for(auto a:adj[curr]){
          if(!visited[a])
          dfs(a,adj,visited);
      }
  }
    int numProvinces(vector<vector<int>> m, int v) {
        // code here
        int ans=0;
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends