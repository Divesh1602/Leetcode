class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
      for(int i=0;i<n-1;i++){
          if(nums[i]==nums[i+1]){
              nums[i]*=2;
              nums[i+1]=0;
          }
      }
        int j=0;
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
        return nums;
    }
};