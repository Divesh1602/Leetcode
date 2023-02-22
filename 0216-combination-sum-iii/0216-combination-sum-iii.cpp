class Solution {
public:
     void helper(int k,int& target,int i,vector<int> op,vector<vector<int>>& ans,int sum){
        if(i==10 || sum>=target || k==0){
            if(sum==target && k==0){
                ans.push_back(op);
            }
            return;
        }
        helper(k--,target,i+1,op,ans,sum);
        op.push_back(i);
        sum+=i;
        helper(k--,target,i+1,op,ans,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        helper(k,n,1,{},ans,0);
        return ans;
    }
};