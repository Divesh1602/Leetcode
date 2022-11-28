class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> m;
        unordered_map<int,int> m1;
        for(auto a:matches){
            m.insert(a[0]);
        }
          for(auto a:matches){
            m1[a[1]]++;
        }
        vector<int> ans;
        vector<vector<int>> res;
        for(auto a :m){
            if(m1.find(a)==m1.end())
                ans.push_back(a);
        }
        sort(ans.begin(),ans.end());
        res.push_back(ans);
        ans.clear();
        for(auto a:m1){
            if(a.second==1)
                ans.push_back(a.first);
        }
        sort(ans.begin(),ans.end());
        res.push_back(ans);
        return res;
    }
};