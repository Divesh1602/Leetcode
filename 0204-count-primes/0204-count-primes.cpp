class Solution {
public:
   
    int countPrimes(int n) {
        vector<bool> ans(n+1,true);
        int ct=0;
        ans[0]=false;
        ans[1]=false;
        for(int i=2;i*i<=n;i++){
            if(ans[i]){
                for(int j=i*i;j<=n;j=j+i)
                    ans[j]=false;
              
            }
        }
        for(int i=2;i<n;i++){
            if(ans[i])
                ct++;
        }
        
        return ct;
    }
};