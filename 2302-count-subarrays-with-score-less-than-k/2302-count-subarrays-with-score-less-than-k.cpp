class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        long long sum=0,ct=0;
       int i=0,j=0;
        while(j<nums.size()){
            sum+=nums[j];
            ct++;
            long long cal=ct*sum;
            if(cal>=k){
                while(cal>=k){
                    sum-=nums[i];
                    i++;
                    ct--;
                    cal=ct*sum;
                }
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};