class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
       unordered_map<int,int> m;
        m[0]++;
        bool flag=false;
        int ans=0,sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k)
                sum--;
            else if(nums[i]>k)
                sum++;
            
            else
                flag=true;
            
            if(flag)
                ans+=m[sum]+m[sum-1];
            else
                m[sum]++;
        }
        return ans;
    }
};