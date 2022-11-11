class Solution {
public:
    int fibonacci(int n){
        long long int ans=0;
        int i=0,j=1;
        
        ans=i+j;
        if(n==2 || n==1)
            return 1;
       if(n==0)
           return 0;
        while(n>2){
            i=j;
            j=ans;
            ans=i+j;
            n--;
        }
        return ans;
    }
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return fibonacci(n-1)+fibonacci(n-2);
    }
};