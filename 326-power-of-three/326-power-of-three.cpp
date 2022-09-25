class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
        if(n<3 && n!=1)
            return false;
        long x=n;
        long long b=3;
        while(n>1){
            
            if(b>x)
                return false;
            else if(b==x)
                return true;
            b=b*3;
            n=n/3;
            
        }
         return 0;
    }
   
};