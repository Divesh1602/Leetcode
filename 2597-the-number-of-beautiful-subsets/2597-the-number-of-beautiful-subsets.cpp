class Solution {
public:
    int ans=0;
    void helper(vector<int>& nums,int k,int i,unordered_map<int,int>& m){
        if(i==nums.size()){
            ans++;
            return;
        }
        
        if(!m[nums[i]+k] && !m[nums[i]-k]){
            m[nums[i]]++;
            helper(nums,k,i+1,m);
            m[nums[i]]--;
        }
        
        helper(nums,k,i+1,m);
        
        
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        helper(nums,k,0,m);
        return ans-1;
    }
};