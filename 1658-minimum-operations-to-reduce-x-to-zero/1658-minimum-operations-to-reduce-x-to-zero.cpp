class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target=0;
        for(auto a:nums)
            target+=a;
        target-=x;
        if(target<0)
            return -1;
        int sum=0;
            int j=0;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
           
            if(sum>target){
                while(sum>target){
                    sum-=nums[j];
                    j++;
                }
            }
             if(sum==target){
                res=max(res,i-j+1);
            }
        }
        if(res==INT_MIN)
            return -1;
        return (nums.size()-res);
    }
};