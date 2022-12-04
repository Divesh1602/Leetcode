class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long suffixsum=0;
        for(int i=nums.size()-1;i>=0;i--)
            suffixsum+=nums[i];
        int suffix=nums.size();
        long long prefixsum=0;
        int prefix=0;
        int res=INT_MAX;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            suffixsum-=nums[i];
            prefix++;
            suffix--;
            if(suffix==0)
            {
                 int cal=abs((prefixsum/prefix)-0);
            if(res>cal){
                res=cal;
                ans=i;
            }
            }
            else{
            int cal=abs((prefixsum/prefix)-(suffixsum/suffix));
            if(res>cal){
                res=cal;
                ans=i;
            }
        }
        }
        return ans;
    }
};