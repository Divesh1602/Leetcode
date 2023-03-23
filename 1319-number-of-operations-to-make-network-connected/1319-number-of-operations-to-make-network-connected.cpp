class Solution {
public:
    void bfs(vector<vector<int>>& adj,vector<int>& vis,int i,int& edges){
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            for(auto a:adj[idx]){
                if(!vis[a]){
                    vis[a]=1;
                    q.push(a);
                }
                else if(a!=i)
                    edges++;
            }
        }
       
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n,vector<int>());
        for(auto a:connections){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int> vis(n,0);
        int edges=0,comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
               comp++;
               
                bfs(adj,vis,i,edges);
            }
           
        }
        comp--;
        edges--;
        if(edges<comp)
            return -1;
        return min(edges,comp);
    }
};