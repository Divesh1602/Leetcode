class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx=0;
        int i=0;
        for(i=0;i<nums.size() && i<=mx;i++)
            mx=max(i+nums[i],mx);
        return (i==nums.size());
    }
};