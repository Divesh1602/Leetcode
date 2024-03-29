class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
       
        int n=a.size();
        int m=a[0].size();
        int r=m-1,t=0;
        if(a[0][0]>x || a[n-1][m-1]<x)
           return false;
        while(t<n && r>=0){
            if(a[t][r]==x)
                return true;
            else if(a[t][r]>x)
                r--;
            else 
                t++;
        }
        return false;
    }
};