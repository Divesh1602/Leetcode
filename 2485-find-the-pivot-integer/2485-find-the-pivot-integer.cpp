class Solution {
public:
    int pivotInteger(int n) {
        int sum=0;
        for(int i=1;i<=n;i++)
            sum+=i;
        int pre=0;
        for(int i=n;i>0;i--){
            sum-=i;
            if(sum==pre)
                return i;
            pre+=i;
        }
        return -1;
    }
};