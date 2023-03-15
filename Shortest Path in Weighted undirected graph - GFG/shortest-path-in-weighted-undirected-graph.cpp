//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        pq.push({0,1});
        dis[1]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            
            for(auto a:adj[node]){
                int u=a.first;
                int wt=a.second;
                if(wt+d<dis[u]){
                    dis[u]=wt+d;
                    parent[u]=node;
                    pq.push({dis[u],u});
                }
            }
        }
        if(parent[n]==n){
            
            return {-1};
        }
        int i=n;
        vector<int> ans;
        while(true){
            ans.push_back(i);
            if(i==1)
            {
              break;
            }
           
            i=parent[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends