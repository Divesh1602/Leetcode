class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>target)
        {
            return 0;
        }
        int sz=nums.size();
        if(nums[sz-1]<target)
        {
            return sz;
        }
        int low=0,high=sz-1;
        while(high-low>1)
        {
            int mid=(high+low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]>target)
            {
                high=mid;
            }
            else
            {
                low=mid;
            }
        }
        if(nums[low]==target)
        {
            return low;
        }
        return high;
    }
};