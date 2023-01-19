class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long total=(long long)((n*(n-1))/2);
        long long ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]-i]++;
        }
      for(int i=0;i<n;i++){
          if(m[nums[i]-i]>1)
              ans+=m[nums[i]-i]-1;
          m[nums[i]-i]--;
      }
        return total-ans;;
    }
};