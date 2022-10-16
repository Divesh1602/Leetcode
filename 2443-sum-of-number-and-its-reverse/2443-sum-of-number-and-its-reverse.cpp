class Solution {
public:
    int rev(int x){
        int res=0;
        while(x>0){
            res=res*10+x%10;
            x=x/10;
        }
        return res;
    }
    bool sumOfNumberAndReverse(int n) {
        for(int i=0;i<=n;i++){
            int x=rev(i);
            if(x+i==n)
                return true;
        }
        return false;
    }
};