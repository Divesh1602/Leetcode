class Solution {
public:
    int rev(int num)
{
  string str = to_string(num);
    reverse(str.begin(), str.end());
    num = stoll(str);
    return num;
}
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<long long,long long> m;
        long long ans=0;
       for(int i=0;i<n;i++){
           long long diff=nums[i]-rev(nums[i]);
           m[diff]++;
       }
        for(int i=0;i<n;i++){
             int diff=nums[i]-rev(nums[i]);
            if(m[diff]>0)
                ans+=(m[diff]-1);
            m[diff]--;
        }
        return ans%1000000007;
    }
};