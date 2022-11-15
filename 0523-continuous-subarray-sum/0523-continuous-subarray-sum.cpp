class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0,ans=0;
        unordered_map<int,int> m;
        
        
        
        for(auto a:nums){
            sum+=a;
            sum=sum%k;
            
            
            if(m.find(sum)!=m.end())
                    return true;
            
           m[ans]++;
            ans=sum;
            
        }
        return false;
    }
};