class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> s;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)
                    s.insert({i,j});
            }
        }
        
        for(auto a:s){
            int row=a.first;
            int column=a.second;
            for(int i=0;i<m;i++)
                matrix[row][i]=0;
            for(int i=0;i<n;i++)
                matrix[i][column]=0;
        }
        
    }
};