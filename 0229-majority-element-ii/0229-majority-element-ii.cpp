class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         unordered_map<int,int> m;
        vector<int> ans;
        int n=nums.size();
        for(auto a: nums)
            m[a]++;
        for(auto a:m){
            int sum=a.second;
            if(sum>n/3)
                ans.push_back(a.first);
        }
            return ans;
    }
};