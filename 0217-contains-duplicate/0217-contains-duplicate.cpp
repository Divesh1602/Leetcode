class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto a:nums)
            m[a]++;
        for(auto a:m)
            if(a.second>1)
                return true;
        
        return false;
    }
};