class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        dis[0][0]=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        while(!pq.empty()){
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1)
            return d;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort=max(abs(grid[nrow][ncol]-grid[row][col]),d);
                    if(newEffort<dis[nrow][ncol]){
                        dis[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                   
                }
            }
        }
        
        return 0;
    }
};