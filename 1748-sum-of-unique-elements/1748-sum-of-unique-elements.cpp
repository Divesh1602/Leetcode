class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto a:nums){
            m[a]++;
        }
        int res=0;
        for(auto a:m){
           if(a.second==1)
               res+=a.first;
        
        }
        return res;
    }
};