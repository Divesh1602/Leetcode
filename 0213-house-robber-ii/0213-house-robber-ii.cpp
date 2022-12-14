class Solution {
public:
    int helper(vector<int>& nums,int i,int j){
        int con=0,ans=0;
        for(int k=i;k<=j;k++){
            int temp=ans;
            if(nums[k]+con>ans)
                ans=nums[k]+con;
                
                con=temp;
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};