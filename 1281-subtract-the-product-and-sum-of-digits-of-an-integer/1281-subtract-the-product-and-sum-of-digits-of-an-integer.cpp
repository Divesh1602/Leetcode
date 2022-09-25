class Solution {
public:
    int subtractProductAndSum(int n) {
        int x=n;
        int res=1;
        
        while(x!=0){
            res=(res)*(x%10);
            x=x/10;
        }
        int sum=0;
        while(n!=0){
            sum=sum+n%10;
            n=n/10;
        }
        return (res-sum);
    }
};