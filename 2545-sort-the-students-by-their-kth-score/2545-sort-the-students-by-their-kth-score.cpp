class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        int n=score.size();
        int m=score[0].size();
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=k;j<m+k;j++){
                v.push_back(score[i][j%m]);
            }
            ans.push_back(v);
        }
       
        sort(ans.begin(),ans.end());
         for(int i=0;i<n;i++){
           
            for(int j=k;j<m+k;j++){
               score[i][j%m]=ans[i][j-k];
            }
            
        }
        reverse(score.begin(),score.end());
        return score;
    }
};