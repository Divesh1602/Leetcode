class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<vector<long long>> v;
        for(int i=0;i<nums.size();i++)
            v.push_back({nums[i],cost[i]});
        sort(v.begin(),v.end());
       long long sum=0;
        for(auto a:v)
            sum+=a[1];
        long long mid = sum/2;
        int st;
        for(auto a:v){
            mid-=a[1];
            st=a[0];
            if(mid<0)
                break;
        }
        long long ans=0;
        for(auto a: v){
            ans+=(long long)(abs(a[0]-st)*a[1]);
            // cout<<st<<" ";
        }
        return ans;
    }
};