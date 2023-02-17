class Solution {
public:
        void helper(vector<int>& nums,int i,set<vector<int>>& ans,vector<int> op){
        if(nums.size()==i){
           
            ans.insert(op);
            return;
        }
       
        helper(nums,i+1,ans,op);
        op.push_back(nums[i]);
        helper(nums,i+1,ans,op);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         set<vector<int>> ans;
       sort(nums.begin(),nums.end());
        helper(nums,0,ans,{});
        vector<vector<int>> op;
        for(auto a:ans)
            op.push_back(a);
        return op;
    }
};