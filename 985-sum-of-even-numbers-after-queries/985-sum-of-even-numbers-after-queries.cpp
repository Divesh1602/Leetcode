class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]%2==0){
               sum+=nums[i];
           }
       }
        for(auto x:queries){
            int a=x[0];
            int b=x[1];
            if(nums[b]%2==0)
                sum-=nums[b];
            nums[b]+=a;
            if(nums[b]%2==0)
                sum+=nums[b];
            ans.push_back(sum);
        }
        return ans;
    }
};