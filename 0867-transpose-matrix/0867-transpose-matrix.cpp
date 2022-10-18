class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m) {
        vector<vector<int>> ans;
        int n=m.size();
        int x=m[0].size();
        for(int i=0;i<x;i++){
            vector<int> ans1;
            for(int j=0;j<n;j++){
                ans1.push_back(m[j][i]);
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};