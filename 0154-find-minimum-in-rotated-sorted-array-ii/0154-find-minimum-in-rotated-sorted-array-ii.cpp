class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int ans=INT_MAX;
        while(i<=j){
            int mid=i+(j-i)/2;
            ans=min(ans,nums[mid]);
            if(nums[mid]==nums[i] && nums[mid]==nums[j])
                {
                i++;
                j--;
            }
            
            else if(nums[j]>=nums[mid])
                j=mid-1;
            else
                i=mid+1;
        }
        return ans;
    }
};