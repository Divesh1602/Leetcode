class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,ans=0;
        unordered_map<int,int> m;
        m[sum]=1;
        for(auto a:nums){
            sum+=a;
            int pre=sum-k;
            if(m.find(pre)!=m.end())
                ans+=m[pre];
            m[sum]++;
        }
        return ans;
    }
};