class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n=nums.size();
        long long total=(long long)(n*(n+1)/2);
        unordered_map<int,int> m;
        long long ct=0;
        int j=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ct+=m[nums[i]];
            m[nums[i]]++;
            while(ct>=k && j<=i){
                if(m[nums[j]]>1){
                    ct-=m[nums[j]]-1;
                }
                m[nums[j]]--;
                j++;
            }
            ans+=i-j+1;
        }
        return total-ans;
    }
};