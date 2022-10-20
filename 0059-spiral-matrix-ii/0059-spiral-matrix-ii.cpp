class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n,vector<int>(n));
       int t=0,l=0,r=n-1,b=n-1;
        int x=1;
        while(t<=b && l<=r){
            for(int i=l;i<=r;i++){
                a[t][i]=x;
                x++;
            }
            t++;
           
            for(int i=t;i<=b;i++){
               a[i][r]=x;
                x++;
            }
            r--;
            if(t<=b){
                for(int i=r;i>=l;i--){
                    a[b][i]=x;
                    x++;
                }
                 b--;
            }
           if(l<=r){
               for(int i=b;i>=t;i--){
                   a[i][l]=x;
                   x++;
               }
               l++;
           }
        }
        return a;
    }
};