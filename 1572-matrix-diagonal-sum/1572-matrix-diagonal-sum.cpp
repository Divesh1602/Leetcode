class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        long  long sum=0;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            sum+=mat[i][i];
             sum+=mat[i][n-i-1];
        }
   
        if(n&1)
        sum-=mat[n/2][n/2];
        return sum;
    }
};