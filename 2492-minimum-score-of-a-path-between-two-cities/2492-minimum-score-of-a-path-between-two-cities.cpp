class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
        for(auto a:roads){
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> dis(n+1,INT_MAX);
       
       
        q.push({1,INT_MAX});
     
        while(!q.empty()){
            int i=q.top().first;
            int d=q.top().second;
            
            q.pop();
            
            for(auto a:adj[i]){
                int ele=a.first;
                int dist=a.second;
                if(d<dist)
                    dist=d;
                if(dist<dis[ele]){
                    dis[ele]=dist;
                    q.push({ele,dist});
                }
                
            }
        }
         
       return dis[n];
    }
};