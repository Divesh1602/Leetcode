class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)
            return false;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
       int n=grid.size();
        int ct=0;
            int delrow[4]={-2,-1,1,2};
        vector<vector<int>> delcol={{-1,1},{-2,2},{-2,2},{-1,1}};
        while(!q.empty()){
            ct++;
            int val=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                for(int j=0;j<delcol[i].size();j++){
                    int nrow=delrow[i]+row;
                    int ncol=delcol[i][j]+col;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==val+1){
                        q.push({grid[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return (ct==n*n);
    }
};