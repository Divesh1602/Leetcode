class Solution {
public:
    int jump(vector<int>& nums) {
        int ct=0;
        int mxJump=0;
        int LastJump=0;
        if(nums.size()==1 || nums[0]==0)
            return 0;
        for(int i=0;i<nums.size();i++){
            
            
            mxJump=max(mxJump,i+nums[i]);
            
            
            if(i==LastJump){
                LastJump=mxJump;
                ct++;
                 if(mxJump>=nums.size()-1)
                return ct;
            }
            
           
        }
        return 0;
    }
};