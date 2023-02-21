class Solution {
public:
    void helper(vector<int>& nums,int i,int& ans,int Xor){
        if(i==nums.size()){
            ans+=Xor;
            return;
        }
        helper(nums,i+1,ans,Xor);
        Xor^=nums[i];
        helper(nums,i+1,ans,Xor);
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int Xor=0;
        helper(nums,0,ans,Xor);
        return ans;
    }
};