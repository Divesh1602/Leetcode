class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(a.begin(),a.end());
        int mn=INT_MAX;
        for(int i=1;i<a.size();i++){
            mn=min(mn,(a[i]-a[i-1]));
            }
        
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]==mn){
                ans.push_back(a[i-1]);
                ans.push_back(a[i]);
                res.push_back(ans);
                ans.pop_back();
                ans.pop_back();
                
            }
        }
        return res;
    }
};