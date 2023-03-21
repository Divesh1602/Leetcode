class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long ct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                ct++;
            else
                ct=0;
            ans+=ct;
        }
        return ans;;
    }
};