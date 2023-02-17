class Solution {
public:
    void helper(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int> op){
        if(nums.size()==i){
            ans.push_back(op);
            return;
        }
       
        helper(nums,i+1,ans,op);
        op.push_back(nums[i]);
        helper(nums,i+1,ans,op);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        helper(nums,0,ans,op);
        return ans;
    }
};