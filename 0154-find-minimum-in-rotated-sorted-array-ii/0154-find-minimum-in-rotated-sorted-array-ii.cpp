class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int ans=INT_MAX;
        while(i<=j){
            int mid=i+(j-i)/2;
           ans=min(ans,nums[mid]);
            if(nums[i]==nums[mid] && nums[j]==nums[mid])
                i++,j--;
            
            else if(nums[mid]>nums[j])
                i=mid+1;
            else
                j=mid-1;
        }
        return ans;
    }
};