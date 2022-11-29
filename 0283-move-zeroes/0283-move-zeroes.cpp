class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int n=nums.size();
         while(j<n && nums[j]!=0)
            j++;
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0 && i>j)
            {
                swap(nums[i],nums[j]);
                while(j<n && nums[j]!=0)
                      j++;
                i=j;
            }
        }
      
    }
};