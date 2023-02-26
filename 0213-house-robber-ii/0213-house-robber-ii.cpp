class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
         
        int prev1=0,prev=nums[0];
     
        for(int i=1;i<nums.size()-1;i++){
            int take=nums[i];
            if(i>1)
                take+=prev1;
            int notTake=prev;
           int curr=max(take,notTake);   
            prev1=prev;
            prev=curr;
        }
        int prev3=0,prev2=nums[1];
         for(int i=2;i<nums.size();i++){
            int take=nums[i];
             if(i>1)
                take+=prev3;
            int notTake=prev2;
            int curr=max(take,notTake);   
            prev3=prev2;
            prev2=curr;        
        }
     
        return max(prev,prev2);
    }
};