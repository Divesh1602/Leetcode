class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans=INT_MAX;
        int zero=0,one=0;
        for(char c:s)
            if(c=='0')
                zero++;
        int n=s.length();
        ans=min(zero,n-zero);
        for(char c:s){
            if(c=='0')
                zero--;
            else
                one++;
            ans=min(ans,zero+one);
        }
        return ans;
    }
};