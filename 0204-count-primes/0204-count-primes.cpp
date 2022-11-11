class Solution {
public:
   
    int countPrimes(int n) {
        vector<bool> ans(n,true);
        int ct=0;
        for(int i=2;i<n;i++){
            if(ans[i]){
                for(long long int j=(long long)i*i;j<n;j=j+i)
                    ans[j]=false;
               ct++;
            }
        }
        
        return ct;
    }
};