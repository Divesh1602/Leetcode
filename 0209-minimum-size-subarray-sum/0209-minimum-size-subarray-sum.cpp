class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX;
        int sum=0;
        int i=0,ct=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            ct++;
            if(sum>=target){
                
                while(sum>=target){
                    res=min(res,ct);
                    sum-=nums[i];
                    i++;
                    ct--;
                }
                
            }
            
        }
        if(res==INT_MAX)
            return 0;
        return res;
    }
};