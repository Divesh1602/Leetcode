class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
     set<int> sr,sc;
        int row=0,col=0;
        long long ans=0;
          for(int i=queries.size()-1;i>=0;i--){
              if(queries[i][0]==0){
                  if(sr.find(queries[i][1])==sr.end())
                  {
                      row++;
                      sr.insert(queries[i][1]);
                      ans+=(n-col)*queries[i][2];
                  }
              }
              else{
                   if(sc.find(queries[i][1])==sc.end())
                  {
                      col++;
                      sc.insert(queries[i][1]);
                      ans+=(n-row)*queries[i][2];
                  }
              }
          } 
        return ans;
   }
};