class Solution {
public:

    int maximumDetonation(vector<vector<int>>& b) {
        
        int n = b.size(); 
        map<int ,vector<int>>adj ;
        
        
        
        
        for(int i =0  ;i<n ;i++ )
        {
            for(int j =0 ; j<n ;j++ )
            {
                if(i!=j)
                {
                    double dis = sqrt((b[i][0]-b[j][0])*(b[i][0]-b[j][0]*1LL) + (b[i][1]-b[j][1])*(b[i][1]-b[j][1]*1LL) );
                    if(dis<=b[i][2])
                    {
                        adj[i].push_back(j) ;
                    }
         
                }
            }
        }
        
        int ans =-1e9; 
        
    
        
        for(int i =0 ; i<n ;i++ )
        {
          vector<int>vis(n, 0 );
           int nn= 0 ; 
                queue<int>q; 
                q.push(i) ;
                vis[i]= 1; 
                while(!q.empty())
                {
                    int node = q.front() ; 
                    nn++  ;
                    q.pop() ;
                    for(auto it: adj[node])
                    {
                        if(!vis[it])
                        {
                            vis[it]=1 ; 
                            q.push(it) ; 
                        }
                    }
                }
                ans = max(ans , nn ) ; 
        
        }
        
        return ans ;
        
    }
};