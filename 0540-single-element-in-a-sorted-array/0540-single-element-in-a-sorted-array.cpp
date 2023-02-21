class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        int i=0,j=n-1;
        int index;
        while(i<=j){
            int mid=i+(j-i)/2;
           index= (mid%2==0)? mid+1:mid-1;
            if(nums[mid]==nums[index])
               i=mid+1;
            else
                j=mid-1;
        }
        return nums[i];
    }
};