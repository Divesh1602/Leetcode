class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==0)
                nums[i]=-1;

        int sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==0)
                res=i+1;
           else if(m.find(sum)==m.end())
                m.insert({sum,i});
            else if(m.find(sum)!=m.end())
                res=max(res,i-m[sum]);
        }
    return res;
    }
    
};