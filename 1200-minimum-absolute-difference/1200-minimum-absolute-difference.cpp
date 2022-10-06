class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        vector<vector<int>> res;
        
        sort(a.begin(),a.end());
        int mn=INT_MAX;
        for(int i=1;i<a.size();i++){
            mn=min(mn,(a[i]-a[i-1]));
            }
        
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]==mn){
                res.push_back({a[i-1],a[i]});
                
                
            }
        }
        return res;
    }
};