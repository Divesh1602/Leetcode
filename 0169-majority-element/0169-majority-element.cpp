class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(auto a: nums)
            m[a]++;
        for(auto a:m){
            int sum=a.second;
            if(sum>n/2)
                return a.first;
        }
            return 0;
    }
};