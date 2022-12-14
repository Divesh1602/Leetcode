class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
    int con=nums[0];
        int ans=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int temp=ans;
            ans=max(nums[i]+con,ans);
            con=temp;
        }
        return ans;
    }
};