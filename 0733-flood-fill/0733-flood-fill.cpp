class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        int ele=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row+1<n && image[row+1][col]==ele && !vis[row+1][col]){
                image[row+1][col]=color;
                vis[row+1][col]=1;
                q.push({row+1,col});
            }
            if(row-1>=0 && image[row-1][col]==ele && !vis[row-1][col]){
                image[row-1][col]=color;
                vis[row-1][col]=1;
                q.push({row-1,col});
            }
            if(col-1>=0 && image[row][col-1]==ele && !vis[row][col-1]){
                image[row][col-1]=color;
                 vis[row][col-1]=1;
                q.push({row,col-1});
            }
            if(col+1<m && image[row][col+1]==ele && !vis[row][col+1]){
                image[row][col+1]=color;
                vis[row][col+1]=1;
                q.push({row,col+1});
            }
        }
        return image;
    }
};