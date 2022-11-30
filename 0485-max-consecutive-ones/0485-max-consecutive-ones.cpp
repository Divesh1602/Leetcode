class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct=0,res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                ct=0;
            else{
            ct++;
          
            res=max(res,ct);
            }
        }
        return res;
    }
};