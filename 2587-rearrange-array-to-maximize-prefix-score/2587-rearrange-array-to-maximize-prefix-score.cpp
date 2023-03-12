class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<long long> temp;
        long long sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            temp.push_back(sum);
        }
        int ct=0;
        for(auto a:temp)
            if(a>0)
                ct++;
        return ct;
    }
};