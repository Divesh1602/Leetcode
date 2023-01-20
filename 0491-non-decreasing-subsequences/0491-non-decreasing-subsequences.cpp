class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         set<vector<int>> ans;
        vector<int> sub;
        for(int i=0; i<1<<nums.size(); i++){ 
            vector<int> temp;
            for(int j=0; j<nums.size(); j++){
                if((1<<j)&i and (temp.empty() or temp.back()<=nums[j])) {
                    temp.push_back(nums[j]);
                }
            }
            if(temp.size()>=2) ans.insert(temp);
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};