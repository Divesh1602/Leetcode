class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int i=0;
        int ans=0;
        long long cal=1;
        for(int j=0;j<nums.size();j++){
            cal*=nums[j];
            if(cal>=k){
                while(cal>=k && i<nums.size()){
                    cal=cal/nums[i];
                    i++;
                  
                }
                
            }
            if(cal<k)
                ans+=j-i+1;
        }
        return ans;
    }
};