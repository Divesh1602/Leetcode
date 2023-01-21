class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0){
            for(int i=0;i<nums1.size();i++)
                if(nums1[i]!=nums2[i])
                    return -1;
            return 0;
        }
        long long ans=-1;
      long long sum_inc=0,sum_dec=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]>nums2[i]){
                int diff=nums1[i]-nums2[i];
                   sum_dec+=diff;
                
            }
             else if(nums1[i]<nums2[i]){
                int diff=nums2[i]-nums1[i];
               
                    sum_inc+=diff;
            }
        }
      
       
        if(sum_inc==sum_dec){
            if(sum_inc%k==0)
            ans=sum_inc/k;
            
        }
        return ans;
    }
};