class Solution {
public:
    void helper(int n,int& ans){
        int i=1;
        
        while(i<n)
            i*=2;
        
        if(i==n)
        {
            ans++;
            return;
        }
        
        if((i-n)<(n-(i/2)))
            n=i-n;
        else
            n=n-(i/2);
        
        ans++;
        helper(n,ans);
        return;
    }
    int minOperations(int n) {
        int ans=0;
        helper(n,ans);
        return ans;
    }
};