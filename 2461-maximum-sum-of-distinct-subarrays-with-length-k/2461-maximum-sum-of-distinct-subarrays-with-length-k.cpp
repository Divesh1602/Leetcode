class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
    long long sum=0;
        long long res=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            m[nums[i]]++;
            if(i>=k-1){
                if(m.size()==k)
                    res=max(res,sum);
                sum-=nums[j];
                m[nums[j]]--;
                if(m[nums[j]]==0)
                    m.erase(nums[j]);
                j++;
            }
        }
        return res;
    }
};