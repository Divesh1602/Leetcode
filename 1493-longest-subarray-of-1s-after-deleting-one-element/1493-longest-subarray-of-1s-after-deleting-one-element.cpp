class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ones=0,zeroes=0;
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==0)
                zeroes++;
            else if(nums[j]==1)
                ones++;
            if(zeroes>1){
                while(zeroes>1){
                    if(nums[i]==0)
                        zeroes--;
                    else if(nums[i]==1)
                        ones--;
                    i++;
                }
                
            }
            ans=max(ans,ones);
            j++;
        }
        if(ones==nums.size())
            ans--;
        return ans;
    }
};