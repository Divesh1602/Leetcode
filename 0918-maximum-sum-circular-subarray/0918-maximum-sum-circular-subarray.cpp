class Solution {
public:
    int normalsub(vector<int>& a){
        int mx=a[0];
        int res=a[0];
        for(int i=1;i<a.size();i++){
            mx=max(a[i],a[i]+mx);
            res=max(mx,res);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& a) {
        int sum=0;
        int mx=normalsub(a);
        if(mx<0)
            return mx;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            a[i]=-a[i];
        }
        int mc=sum+normalsub(a);
        return max(mx,mc);
    }
};