class Solution {
public:
    void nextPermutation(vector<int>& nums) {
 int pt=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                pt=i-1;
                break;
            }
            
        }
        if(pt<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[pt]){
                swap(nums[i],nums[pt]);
                reverse(nums.begin() + pt + 1,nums.end());
                return;
            }
        }
      
    }
};