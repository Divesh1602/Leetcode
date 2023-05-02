class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(auto a:nums){
            if(a<0)
                ans*=-1;
            else if(a>0)
                ans*=1;
            else
                ans*=0;
        }
        return ans;
    }
};