class Solution {
public:
    bool judgeSquareSum(int c) {
      
        int i=0;
        int j=sqrt(c);
        long long ans;
        while(i<=j){
            ans=(long long)(i*i)+(long long)(j*j);
            if(ans==c)
                return true;
           else if(ans>c)
                j--;
            else
                i++;
        }
        return false;
    }
};