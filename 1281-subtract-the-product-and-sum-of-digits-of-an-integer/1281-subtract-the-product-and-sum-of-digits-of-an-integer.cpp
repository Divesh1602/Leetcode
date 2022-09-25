class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int res=1;
         int sum=0;
        
       
       
        while(n!=0){
            sum=sum+n%10;
            res=(res)*(n%10);
            n=n/10;
        }
        return (res-sum);
    }
};