class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long sum=0;
        for(auto a:beans)
            sum+=a;
        int n=beans.size();
        long long res=LLONG_MAX;
        for(int i=0;i<beans.size();i++){
            long long temp=(long long)sum-(n-i)*(long long)beans[i];
            res=min(res,temp);
        }
        return res;
    }
};