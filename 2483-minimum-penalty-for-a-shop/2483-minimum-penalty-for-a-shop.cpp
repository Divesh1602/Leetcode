class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length()-1;
        int penalty=0;
        for(int i=0;i<=n;i++){
            if(customers[i]=='N')
                penalty++;
        }
        int res=n+1;
        int ans=penalty;
        for(int i=n;i>=0;i--){
            if(customers[i]=='N')
                penalty--;
            else
                penalty++;
            
            if(ans>=penalty){
                res=min(res,i);
                ans=penalty;
            }
        }
        return res;
    }
};