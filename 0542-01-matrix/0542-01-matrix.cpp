class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        vector<vector<int>> result(rows,vector<int>(cols,0));;
        queue<pair<pair<int,int>,int>> q;
        for(int i =0; i<rows;i++)
        {
            for(int j = 0;j<cols;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int sr = q.front().first.first;
            int sc = q.front().first.second;
            int dis = q.front().second;
            result[sr][sc] = dis;
            q.pop();
            for(int i=0;i<4;i++){
                int delR = sr + delRow[i];
                int delC = sc + delCol[i];
                if(delR>=0 && delR<rows && delC>=0 && delC<cols &&vis[delR][delC] == 0 && mat[delR][delC] == 1){
                    q.push({{delR,delC},dis+1});
                    vis[delR][delC]=1;

                }
            }

            

        }
        return result;

        
    }
};
