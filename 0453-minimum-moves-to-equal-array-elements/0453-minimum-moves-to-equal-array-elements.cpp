class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn=INT_MAX;
        int ans=0;
        for(auto a: nums)
            mn=min(mn,a);
        for(auto a:nums)
            ans+=a-mn;
        return ans;
        
    }
};