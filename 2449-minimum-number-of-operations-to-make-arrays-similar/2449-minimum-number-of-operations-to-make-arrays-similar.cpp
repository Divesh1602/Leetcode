class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> even_nums,odd_nums,even_target,odd_target;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                even_nums.push_back(nums[i]);
            else
                odd_nums.push_back(nums[i]);
            if(target[i]%2==0)
                even_target.push_back(target[i]);
            else
                odd_target.push_back(target[i]);
        }
        
        
        sort(even_nums.begin(),even_nums.end());
        
         sort(odd_nums.begin(),odd_nums.end());
        
         sort(even_target.begin(),even_target.end());
        
        sort(odd_target.begin(),odd_target.end());
        
        
        long long ans=0;
        for(int i=0;i<even_nums.size();i++){
            if(even_nums[i]>even_target[i])
                ans+=even_nums[i]-even_target[i];
        }
         for(int i=0;i<odd_nums.size();i++){
            if(odd_nums[i]>odd_target[i])
                ans+=odd_nums[i]-odd_target[i];
        }
        return ans/2;
    }
};