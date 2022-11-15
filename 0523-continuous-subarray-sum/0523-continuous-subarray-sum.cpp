class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0,ans=0;
        unordered_map<int,int> m;
        
        
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum=sum%k;
            
            
            if(m.find(sum)!=m.end())
                    return true;
            
           m[ans]++;
            ans=sum;
            
        }
        return false;
    }
};