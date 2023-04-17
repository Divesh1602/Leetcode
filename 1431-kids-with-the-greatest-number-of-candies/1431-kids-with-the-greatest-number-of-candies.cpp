class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=INT_MIN;
        vector<bool> ans;
        for(auto a:candies)
            mx=max(mx,a);
        for(auto a:candies){
            if(a+extraCandies>=mx)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};