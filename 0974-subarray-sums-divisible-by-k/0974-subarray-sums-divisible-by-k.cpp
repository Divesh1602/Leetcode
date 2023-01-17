class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int j=0;
        int ans=0;
        int n=nums.size();
        int sum=0;
        m[0]=1;
        while(j<n){
            sum+=nums[j];
            int remainder=sum%k;
            if(remainder<0)
                remainder+=k;
            if(m.find(remainder)!=m.end())
                ans+=m[remainder];
            
            m[remainder]++;
            j++;
        }
        return ans;
    }
};