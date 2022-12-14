class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==1)
            return {{strs[0]}};
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(auto a:strs){
            string str=a;
            sort(a.begin(),a.end());
            m[a].push_back(str);
        }
        for(auto a: m)
            ans.push_back(a.second);
        return ans;
    }
};