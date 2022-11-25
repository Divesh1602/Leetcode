class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int pre=0;
        for(auto a:nums)
            sum+=a;
        for(int k=0;k<nums.size();k++){
             sum-=nums[k];
            if(pre==sum)
                return k;
             pre+=nums[k];
          
        }
        return -1;
    }
};