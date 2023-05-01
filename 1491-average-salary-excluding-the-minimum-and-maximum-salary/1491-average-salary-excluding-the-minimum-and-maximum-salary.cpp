class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(auto a:salary){
            mn=min(mn,a);
            mx=max(mx,a);
            sum+=a;
        }
     sum=sum-mn-mx;
       double n=salary.size()-2;
        return sum/n;
    }
};