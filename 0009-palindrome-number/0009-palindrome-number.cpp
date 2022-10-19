class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        if(x<0)
            return false;
        long long res=0;
        while(x>0){
            res=res*10+x%10;
            x=x/10;
        }
        if(res==n)
            return true;
        return false;
    }
};