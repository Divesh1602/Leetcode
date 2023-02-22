class Solution {
public:
    void helper(vector<int>& nums,int& target,int i,vector<int> op,vector<vector<int>>& ans,int sum){
        if(i==nums.size() || sum>=target){
            if(sum==target){
                ans.push_back(op);
            }
            return;
        }
        helper(nums,target,i+1,op,ans,sum);
        op.push_back(nums[i]);
        sum+=nums[i];
        helper(nums,target,i,op,ans,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        helper(candidates,target,0,{},ans,0);
        return ans;
    }
};