class Solution {
public:
    int numSubseq(vector<int>& nums, int t) {
        int mod=1e9+7;
        sort(nums.begin(),nums.end());
     
       
        vector<int> p={1};
        for(int i=0;i<nums.size();i++){
            p.push_back((p.back()*2)%mod);
        }
        
        
        int i=0;
        long long ans=0;
        int j=nums.size()-1;
        while(i<=j){
            if(nums[i]+nums[j]<=t){
             
                ans=(ans+p[j-i])%mod;
                i++;
            }
            else{
                j--;
            }
        }
        
      
        return ans;
    }
};