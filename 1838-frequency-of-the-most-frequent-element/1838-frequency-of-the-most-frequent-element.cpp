class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        long long cal=0;
        long long ct=1;
        long long res=1;
        while(j<n){
            cal+=ct*(nums[j]-nums[j-1]);
            ct++;
            if(cal<=k){
                 res=max(res,ct);
            }
            else if(cal>k){
                while(cal>k){
                    cal-=nums[j]-nums[i];
                    ct--;
                    i++;
                }
            }
           j++;
        }
        return int(res);
       
    }
};