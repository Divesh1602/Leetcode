class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int res=0;
        for(auto a:s){
            if(s.find(a-1)==s.end())
            {
                int ct=1;
                while(s.find(a+ct)!=s.end())
                    ct++;
                res=max(res,ct);
            }
        }
        return res;
    }
};