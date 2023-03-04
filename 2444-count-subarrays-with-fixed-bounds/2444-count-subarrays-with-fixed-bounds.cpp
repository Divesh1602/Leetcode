class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int mx=-1,mn=-1;
        int ind=-1;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=minK && maxK>=nums[i]){
                mn=(nums[i]==minK)? i:mn;
                mx=(nums[i]==maxK)?i:mx;
                ans+=max(0,min(mn,mx)-ind);
            }
            else{
                ind=i;
                mn=-1;
                mx=-1;
            }
        }
        return ans;
    }
};