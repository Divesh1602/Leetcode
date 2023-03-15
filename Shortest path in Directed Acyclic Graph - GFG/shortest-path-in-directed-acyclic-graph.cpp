//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void topo(int node,vector<vector<pair<int,int>>>& adj,vector<int>& vis,stack<int>& st){
        vis[node]=1;
        for(auto a:adj[node]){
            if(!vis[a.first])
            topo(a.first,adj,vis,st);
        }
        st.push(node);
        return;
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        stack<int> st;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
            topo(i,adj,vis,st);
        }
        
        vector<int> dis(n);
        for(int i=0;i<n;i++)
        dis[i]=1e9;
        dis[0]=0;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            for(auto a:adj[i]){
            int v=a.first;
            int wt=a.second;
            dis[v]=min(dis[v],dis[i]+wt);
            }
        }
        for(auto &a:dis)
        if(a==1e9)
        a=-1;
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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