class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        
        dis[0][0]=1;
        priority_queue<pair<int ,pair<int,int>>,vector<pair<int ,pair<int,int>>>,greater<pair<int ,pair<int,int>>>> pq;
        
        pq.push({1,{0,0}});
       
        
        while(!pq.empty()){
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                int nrow=row+i;
                int ncol=col+j;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0){
                    if(d+1<dis[nrow][ncol]){
                        dis[nrow][ncol]=d+1;
                        pq.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
            }
        }
        
        return (dis[n-1][n-1]==INT_MAX)?-1:dis[n-1][n-1];
    }
};