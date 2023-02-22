class Solution {
public:
      void helper(int ind,int target,vector<int>& nums,vector<int> op,vector<vector<int>>& ans){
 
            if(target==0){
                ans.push_back(op);
                  return;
            }
          
     for(int i=ind;i<nums.size();i++){
           if(i>ind && nums[i]==nums[i-1])
               continue;

           if(nums[i]>target)
               break;
           op.push_back(nums[i]);
           helper(i+1,target-nums[i],nums,op,ans);
           op.pop_back();
    }
       
        return;
     
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
       
        vector<vector<int>> ans;
        helper(0,target,candidates,{},ans);
       
        return ans;
    }
};